/*
 * time��2019��12��7�� 11��41��
 * author���δ�
 * ������Ҫ��װ�Ĳ����������Ⱪ¶��ϸ��
*/
#include "NodeInfo.h"
#include "NodeOpe.h"
#include "State.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ȡ�ļ�״̬�����ͷ�ļ�
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

/*
 * Author: л���
 * ���ã��ж�·���յ��Ƿ�Ϊ�ļ�
 * �÷�������path���ļ���·��,������ļ��򷵻�true�����򷵻�false
*/
boolean file_exsists(char *path)
{
	struct _stat buf;
	//����ļ�״̬��Ϣ
	_stat(path, &buf);
	if(_S_IFREG & buf.st_mode) //������ļ�������true
	{
		return true;
	}
	else  //��������ļ����������������false
	{
		return false;
	}
}

/*
 * Author: л���
 * ���ã��ж�·���յ��Ƿ�Ϊ�ļ���
 * �÷�������path���ļ��е�·��,������ļ����򷵻�true�����򷵻�false
*/
boolean folder_exsists(char *path)
{
	struct _stat buf;
	//����ļ�״̬��Ϣ
	_stat(path, &buf);
	if(_S_IFDIR & buf.st_mode) //������ļ��У�����true
	{
		return true;
	}
	else  //��������ļ��л��������������false
	{
		return false;
	}
}

/*
 * Author: л���
 * ���ã������ļ�(��)���������һ��'\'��ʼ��ĩβ
 * �÷�������path���ļ��ľ���·�����ļ������ڷ���NULL
 */
char * get_name(char * path)
{
    if(path == NULL || 0==strlen(path))  //��·�������ڷ���NULL
    {
    	return NULL;
	}

	char *name = (char *)malloc(sizeof(char) * (strlen(path)+1));
	int idx; //λ�ñ��
	int i, j;
	//��ȡ��·��β���ļ���
	for(i = strlen(path); path[i] != '\\'; i--)
	{
		idx = i;
	}

	for(i = idx, j=0; path[i] != '\0'; i++, j++)
	{
		name[j] = path[i];
	}
	name[j] = '\0';

	// ������ȥ����׺���Ĵ��룬����Ҫʹ��

	// if(file_exsists(path))  //������ļ��������׺��
	// {
	// 	for(i=strlen(name); i>=0 && name[i]!='.'; i--)
	// 	{
	// 		;	//�����
	// 	}

	// 	if ( -1!=i || 0!=i  )	//�ų��ļ���û��'.'���ļ��Լ���".gitignore"�������ļ�
	// 	{
	// 		name[i] = '\0';
	// 	}
	// }
	char *name1 = (char *)malloc(sizeof(char) * (strlen(name)+1));
	strcpy(name1, name);
	free(name);
	return name1;
}


/*
 * Author: л���
 * ���ã������ļ���չ����ָ��
 * �÷�������path���ļ��ľ���·������չ�������ڷ���NULL
 */
char *get_extension(char *path)
{
	if(path == NULL || strchr(path, '.') == NULL)  //��·�������ڻ��׺���������򷵻�NULL
    {
    	return NULL;
	}
	char *extension = (char *)malloc(sizeof(char) *(strlen(path)+1));
	int idx; //λ�ñ��
	int i, j;
	//��ȡ��·��β���ļ���չ��
	for(i = strlen(path); path[i] != '.'; i--)
	{
		idx = i;
	}
	for(i = idx, j=0; path[i] != '\0'; i++, j++)
	{
		extension[j] = path[i];
	}
	extension[j] = '\0';
	char *extension1 = (char *) malloc(sizeof(char) * (strlen(extension)+1));
	strcpy(extension1, extension);
	free(extension);
	return extension1;
}


/*
 * Author: �δ�  Modify:л���
 * ���ã������ļ��Ĵ�С����λΪByte(�ֽ�)
 * �÷�������path���ļ���·�����ļ������ڷ���-1
 */
long get_file_size(char *path)
{
    long size;
    FILE* f = fopen(path, "rb");
    fseek(f, 0L, SEEK_END);
    size = ftell(f);
    fclose(f);
    return size;
}



/*
 * Author: л���
 * ���ã���ȡ�ļ�����·��
 * �÷�������path���ļ���·��,·��������ʱ����NULL
 * ��ע���˺���������bug
*/
char * get_dir(char * path)
{
	if(path == NULL)
	{
		return NULL;
	}
	char *absolut_path = (char *)malloc(sizeof(char) * (strlen(path)+1));
	int i, j ;
	for(i = 0, j=0; i<strlen(path); i++, j++)
	{
		absolut_path[i] = path[i];
		if(path[i] == '\\')
		{
			absolut_path[j+1] = '\\';
			j++;
		}
	}
	absolut_path[j-2] = '\0';
	printf("%s", absolut_path);
	char *absolut_path1 = (char *) malloc(sizeof(char) * (strlen(absolut_path)+1));
	strcpy(absolut_path1, absolut_path);
	free(absolut_path);
	return absolut_path1;
}

/*
 * Author: л���
 * ���ã���ȡ·���ļ������Ϣ
 * �÷�������path���ļ���·��,·��������ʱ����NULL
*/
FileInfo * create_info_node(char * path)
{
	struct _stat buf;
	int result;
	int filenum = 0;
	result = _stat(path, &buf); //����ļ�״̬��Ϣ
	FileInfo * filehead = (FileInfo *)malloc(sizeof(FileNode));
	if(filehead == NULL || path == NULL || result != 0)// ���ڴ����ʧ�ܣ�·�������ڻ��ļ������ڣ�����NULL
	{
		return NULL;
	}
	char *modify  = (char *)malloc(sizeof(char) * strlen(ctime(&buf.st_mtime)));
	strcpy(modify, ctime(&buf.st_mtime));
	int i;
	for(i = 0; modify[i] != '\n'; i++ );
	modify[i] = '\0';
	filehead->modifyTime = modify;   //����޸�ʱ��
	filehead->modifyTimeNum = buf.st_mtime;  //����޸�ʱ��

	strcpy(filehead->modifyTime, modify);
	filehead->path = path;
	filehead->name = get_name(path);
	if(file_exsists(path))  //������ļ�
	{
		filehead->type = file;
		filehead->size = buf.st_size;
		filehead->extension = get_extension(path);
		filehead->innerFileNum = -1;
	}
	else if(folder_exsists(path)) //������ļ���
	{
		filehead->type = folder;
		filehead->size = -1;
		filehead->extension = NULL;
		struct dirent *entry;
    	DIR * dir = NULL;
    	dir = opendir(path);
		while((entry = readdir(dir)) != 0)
		{
			filenum++;  //�ļ���Ŀ�Ӽ�
		}
		closedir(dir);
		filehead->innerFileNum = filenum - 2;
	}

	return filehead;
}



/*
 * Author���δ�
 * ���ã���spacing����������name������spacing���ַ��ر��ض�
*/
void print_name(char *name, int spacing)
{
    if (strlen(name) > spacing)
    {
        char *p = name;
        int i;
        for (i=0; i<spacing-1; ++i)
        {
            printf("%c", *p++);
        }
        printf("..");
    }
    else
    {
        printf("%s", name);
        int i;
        for (i=strlen(name); i<=spacing; ++i)
        {
            printf(" ");
        }
    }
    printf("  ");
    return;
}



/*
 * Author��л���
 * ���ã�ǰ���������ļ��������ڵ��name
*/
void pre_order_in_name(FilesBiTree root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%s\n", root->info->name);

	pre_order_in_name(root->lch);
	pre_order_in_name(root->rch);
}



/*
 * Author���δ�
 * ���ã��ͷ�һ�������ڴ�
 * ������֪���������������Ҫ��FilesBiTree��NULL
*/
void free_tree(FilesBiTree tree)
{
	if (NULL == tree)
		return;
	free(tree->lch);
	free(tree->rch);
	free(tree);
	return;
}























#if 0
/*
 * Author: �δ�  Modify:л���
 * ���ã���ȡ�ļ���ǰ״̬
 * �÷�������path���ļ���·��,��ӡ���ļ��������Ϣ
*/
void get_file_status(char *path)
 {
     struct _stat buf;
     int result;
     //����ļ�״̬��Ϣ
     result = _stat(path , &buf );
     //��ʾ�ļ�״̬��Ϣ
    if( result != 0 )
        printf( "��ʾ�ļ�״̬��Ϣ����" );//����ʾ�����ԭ����No such file or directory���޴��ļ���������
     else
     {
         printf("�ļ���С: %ld", buf.st_size);
         printf("\n�ļ�����ʱ��: %s", ctime(&buf.st_ctime));
         printf("��������: %s", ctime(&buf.st_atime));
         printf("����޸�����: %s", ctime(&buf.st_mtime));
     }
	 return;
 }
#endif
