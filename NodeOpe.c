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
// char * get_name(char * p)
// {
//     if(p == NULL || 0==strlen(p))  //��·�������ڷ���NULL
//     {
//     	return NULL;
// 	}

// 	char *path = (char *)malloc(sizeof(char) * (strlen(p)+1));
// 	char *name = (char *)malloc(sizeof(char) * (strlen(p)+1));
// 	strcpy(path, p);
// 	int idx; //λ�ñ��
// 	int i, j;
// 	//��ȡ��·��β���ļ���
// 	for(i = strlen(path); path[i] != '\\'; i--)
// 	{
// 		idx = i;
// 	}

// 	for(i = idx, j=0; path[i] != '\0'; i++, j++)
// 	{
// 		name[j] = path[i];
// 	}
// 	name[j] = '\0';

// 	// ������ȥ����׺���Ĵ��룬����Ҫʹ��

// 	// if(file_exsists(path))  //������ļ��������׺��
// 	// {
// 	// 	for(i=strlen(name); i>=0 && name[i]!='.'; i--)
// 	// 	{
// 	// 		;	//�����
// 	// 	}

// 	// 	if ( -1!=i || 0!=i  )	//�ų��ļ���û��'.'���ļ��Լ���".gitignore"�������ļ�
// 	// 	{
// 	// 		name[i] = '\0';
// 	// 	}
// 	// }
// 	char *name1 = (char *)malloc(sizeof(char) * (strlen(name)+1));
// 	strcpy(name1, name);
// 	free(name);
// 	free(path);
// 	return name1;
// }



char * get_name(char * path)
{
    if(path == NULL || 0==strlen(path))  //��·�������ڷ���NULL
    {
    	return NULL;
	}

	char *name = (char *)malloc(sizeof(char) * (strlen(path)+1));
	char *ch = name;
	int length = strlen(path);
	int i = length;

	while (*path)	//�Ƶ����
	{
		++path;
	}

	while (i>=0 && *(path-1) != '\\')	//�ҵ����ҵ�'\'
	{
		--i;
		--path;
	}

	while (*path!='\0')	//����
	{
		*ch++ = *path++;
	}
	*ch = '\0';
	char * name1 = (char *)malloc(sizeof(char) * (strlen(name)+1));
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
	if(path == NULL || 0==strlen(path) ||strchr(path, '.') == NULL)  //��·�������ڻ��׺���������򷵻�NULL
    {
    	return NULL;
	}

	char *name = (char *)malloc(sizeof(char) * (strlen(path)+1));
	char *ch = name;
	int length = strlen(path);
	int i = length;

	while (*path)	//�Ƶ����
	{
		++path;
	}

	while (i>=0 && *(path-1) != '.')	//�ҵ����ҵ�'.'
	{
		--i;
		--path;
	}

	while (*path!='\0')	//����
	{
		*ch++ = *path++;
	}
	*ch = '\0';
	char * name1 = (char *)malloc(sizeof(char) * (strlen(name)+1));
	strcpy(name1, name);
	free(name);
	return name1;
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
	// printf("@@%s@@\n", path);
	if (NULL==path || 0==strlen(path))
	{
		return NULL;
	}
	FileInfo * infoNode = (FileInfo *)malloc(sizeof(FileNode));
	struct _stat buf;
	int result;
	int filenum = 0;
	result = _stat(path, &buf); //����ļ�״̬��Ϣ
	if(infoNode == NULL || path == NULL || result != 0)// ���ڴ����ʧ�ܣ�·�������ڻ��ļ������ڣ�����NULL
	{
		return NULL;
	}
	char *modify  = (char *)malloc(sizeof(char) * strlen(ctime(&buf.st_mtime)));
	strcpy(modify, ctime(&buf.st_mtime));
	int i;
	for(i = 0; modify[i] != '\n'; i++ );
	modify[i] = '\0';
	infoNode->modifyTime = modify;   //����޸�ʱ��
	infoNode->modifyTimeNum = buf.st_mtime;  //����޸�ʱ��
	strcpy(infoNode->modifyTime, modify);
	infoNode->path = path;
	// printf("%s.i\n", __func__);
	// ��i��j֮���ƺ���bug
	infoNode->name = get_name(path);
	// printf("%s.j\n", __func__);
	if(file_exsists(path))  //������ļ�
	{
		// printf("%s:file_start\n", __func__);
		infoNode->type = file;
		infoNode->size = buf.st_size;
		infoNode->extension = get_extension(path);
		infoNode->innerFileNum = -1;
		// printf("%s:file_end\n", __func__);
	}
	else if(folder_exsists(path)) //������ļ���
	{
		// printf("%s:folder_start\n", __func__);
		infoNode->type = folder;
		infoNode->size = -1;
		infoNode->extension = NULL;
		struct dirent *entry;
		// printf("%s:folder_1\n", __func__);
    	DIR * dir = NULL;
    	dir = opendir(path);
		// printf("%s:folder_2\n", __func__);
		//ȥ��СԲ��
		readdir(dir);
		readdir(dir);
		while((entry = readdir(dir)) != 0)
		{
			++filenum;  //�ļ���Ŀ�Ӽ�
		}
		// printf("filenum = %d\n", filenum);
		// printf("%s:folder_3\n", __func__);
		closedir(dir);
		infoNode->innerFileNum = filenum;
		// printf("%s:folder_end\n", __func__);
	}
	// printf("%s:end\n", __func__);
	return infoNode;
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



void pre_order_in_path(FilesBiTree root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%s\n", root->info->path);

	pre_order_in_path(root->lch);
	pre_order_in_path(root->rch);
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

/*
 * Author���δ�
 * ����������Byte��С����ȡ���ʵ�λ�Ĵ�С
 * ��������棬ֻ���������һ����freeһ��
*/
char *get_size_string(long size)
{
	int unit;	//��ǵ�λ
	long dSize;
	long long gb = 1024 *1024 *1024 * 1024;	//ֱ��ʹ�û����
	if (size<=0)
	{
		char *string = (char *)malloc(sizeof(char) *2);
		string[0] = '0';
		string[1] = '\0';
		return string;
	}

	if (size < 1024)
	{
		dSize = size * 100;
		unit = 1;
	}
	else if (size < 1024 *1024)
	{
		dSize = size / 1024.0 * 100;
		unit = 2;
	}
	else if (size < 1024 * 1024 *1024)
	{
		dSize = size / 1024.0 / 1024.0 * 100;
		unit = 3;
	}
	else if (size < gb)
	{
		dSize = size / 1024.0 / 1024.0 / 1024.0 * 100;
		unit = 4;
	}

	int cnt = 0;	//���size��λ��
	long num = dSize;
	char str[20] = {'\0'};	//��longתΪchar����ת
	while (num!=0)
	{
		str[cnt++] = (int)(num%10) + '0';
		num /= 10;
	}
	char *string = (char *)malloc(sizeof(char) * (cnt+5));
	char *p = string;

	while (cnt>=0)
	{
		if (2 == cnt)
		{
			*p++ = '.';
			*p++ = str[--cnt];
			continue;
		}
		*p++ = str[--cnt];
	}
	*(p-1) = ' ';
	if (1 == unit)
	{
		strcpy(p, "Byte");
		p[4] = '\0';
	}
	else if (2 == unit)
	{
		strcpy(p, "KB");
		p[2] = '\0';
	}
	else if (3 == unit)
	{
		strcpy(p, "MB");
		p[2] = '\0';
	}
	else if (4 == unit)
	{
		strcpy(p, "GB");
		p[2] = '\0';
	}
	return string;
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
