#include "NodeInfo.h"
#include "State.h"
#include "NodeOpe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPACING 15	//���������࣬���������࣬ʣ����ַ��ͻᱻ�ض�



/*
 * Author: л��� Modify���δ�
 * ���ã������ļ�Ŀ¼�µ������ļ���·��
 * �÷�������path���ļ��ľ���·����path�����ڷ���NULL
*/
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
 * Author���δ�
 * ���ܣ�ֻ����path�ļ����µ�ͬһ����ֵܶ�����(�˻�Ϊ����)
*/
FilesBiTree create_blising_tree(char *path)
{
	FilesBiTree root = (FilesBiTree) malloc (sizeof(FileNode));
	FileNode *node = root;
	if(node == NULL ) //������ռ�ʧ��
	{
		return NULL;
	}
	node->rch = NULL;
	node->info = create_info_node(path); //��ȡ�ļ���Ϣ
	int fileNum = node->info->innerFileNum;
	char **p = get_inner_pathes(node->info);  //��ȡ�ļ����ڵ��ļ�·��
	node->lch = (FilesBiTree) malloc (sizeof(FileNode));
	node = node->lch;
	node->info = create_info_node(p[0]);
	node->lch = NULL;

	int i;
	for(i = 1; i < fileNum; ++i)
	{
		node->rch = (FilesBiTree) malloc (sizeof(FileNode)); //���ӽ��ΪĿ¼�µĺ����ļ�
		node = node->rch;
		node->lch = NULL;
		node->info = create_info_node(p[i]);
	}
	node->rch = NULL;	//�������һ���Һ���

	return root;
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



/*
 * Author:�δ�
 * ʵ�ֹ��ܣ�ֻ�����Ŀ¼�µ��ļ�(��)�����֣����ж���
 */
int list_files_name_only(FilesBiTree tree)
{
    FileNode *node = tree;
    if (node->info->type != folder)     //�������ļ��У�ֱ���˳�
    {
        return Error;
    }
    if (NULL == node->lch)  //���ǿ��ļ��У���ʾ���˳�
    {
        printf("���ļ���\n");
        return OK;
    }
    FilesBiTree p = tree->lch;

    int maxLength = 0;
    int tempLength = 0;
    int spacing = 0;

    for (int i=0; i<(node->info->innerFileNum); ++i, p=p->rch)
    {
        if (maxLength < (tempLength=strlen(p->info->name)))
        {
            maxLength = tempLength;
        }
    }
    //��ȡ��������ַ���������ȴ���Ԥ�������ȣ�����ΪԤ��������
    spacing = maxLength < MAX_SPACING ? maxLength : MAX_SPACING;
    p = tree->lch;  //��ͷ��ʼ���
    // printf("%d %d\n", maxLength, spacing);
    for (int i=1; i<node->info->innerFileNum; ++i, p=p->rch)
    {
        print_name(p->info->name, spacing);
        if (0 == i%4)
        {
            printf("\n");
        }
    }
    printf("\n");
    return OK;
}



/*
 * Author���δ�
 * ���ã�ֻ�����Ŀ¼�µ��ļ�(��)�����֣����ж���
*/
int list_files_name_only_in_path(char *path)
{
    FilesBiTree blisingTree = create_blising_tree(path);
    list_files_name_only(blisingTree);
	free_tree(blisingTree);
    return OK;
}