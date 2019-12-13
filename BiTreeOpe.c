#include"BiTreeOpe.h"
#include"NodeOpe.c"
#include "NodeInfo.h"

// * Author: л��� Modify���δ�
// * ���ã������ļ�Ŀ¼�µ������ļ���·��
// * �÷�������path���ļ��ľ���·����path�����ڷ���NULL

char **get_inner_pathes(FileInfo *info)
{
	char *path = info->path;
	char **paths_arr = (char ** )malloc(sizeof(char* ) * info->innerFileNum);  //��̬�����ڴ�ռ�
	DIR *dir = opendir(path);
	struct dirent *entry;
	int num;
	int lenth = strlen(path); //��ȡ�ļ�·���ĳ���
	if(paths_arr == NULL || dir == NULL)//��pathΪ��·��������,���ڴ����ʧ�ܣ�����NULL
	{
		return NULL;
	}
	//��СԲ��ȥ��
	readdir(dir);
	readdir(dir);

	for (num=0; num<info->innerFileNum; ++num)
	{
		entry = readdir(dir);
		// char *name = (char *)malloc(sizeof(char) * (strlen(entry->d_name)+1));
		// strcpy(name, entry->d_name);

		paths_arr[num] = (char *) malloc(sizeof(char) * (lenth+strlen(entry->d_name)+2));
		// �������ռ䣬һ����\\��һ����\0
		if(paths_arr[num] == NULL) //�ռ����ʧ�ܣ�����NULL
		{
			return NULL;
		}

		strcpy(paths_arr[num], path);
		paths_arr[num][lenth] = '\\';  //�ָ���

		strcpy(paths_arr[num]+lenth+1, entry->d_name);  //���ɾ���·��
		// paths_arr[num][j] = '\0';
	}
	closedir(dir);
	return paths_arr;
}

/*
 * Author: л���  Modify:�δ�
 * ���ã������ļ�Ŀ¼�������ĸ��ڵ�
 * �÷�������path���ļ��ľ���·����path�����ڷ���NULL
 */

FilesBiTree create_files_bitree(char *path)
{
	FilesBiTree root = (FilesBiTree) malloc (sizeof(FileNode));
	if(root == NULL   ) //������ռ�ʧ��
	{
		return NULL;
	}
	root->info = create_info_node(path); //��ȡ�ļ���Ϣ
	if(root->info == NULL)  //���ļ������ڣ�����NULL
	{
		free(root);
		return NULL;
	}

	if(file == root->info->type) //������ļ�
	{
		root->lch = NULL;
	}
	else //������ļ���
	{
		if (0 == root->info->innerFileNum)	//��Ϊ���ļ���
		{
			root->lch = NULL;
			return root;
		}
		char **p = get_inner_pathes(root->info);  //��ȡ�ļ����ڵ��ļ�·��

		root->lch = create_files_bitree(p[0]); //���ӽ��ΪĿ¼�µĵ�һ�� �ļ�
		FilesBiTree pointer = root->lch;
		int i;
		for(i = 1; i < root->info->innerFileNum; i++)
		{
			pointer->rch = create_files_bitree(p[i]); //���ӽ��ΪĿ¼�µĺ����ļ�
			pointer = pointer->rch;
		}
		pointer->rch = NULL;	//�������һ���Һ���
	}
	root->rch = NULL;
	return root;
}

void pre_order(FilesBiTree root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%s\n", root->info->baseName);

	pre_order(root->lch);
	pre_order(root->rch);
}