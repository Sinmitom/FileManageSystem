#include "State.h"
#include "NodeInfo.h"
#include "NodeOpe.h"
#include "BiTreeOpe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get_case_key(char *option);

int main(void)
{
    char command[10][100];
    FilesBiTree root = NULL;
    FileNode *curNode = NULL;
    char curPath[100];
    while (1)
    {
        printf("FMS %s>", curPath);
        scanf("%s", command[0]);
        switch (get_case_key(command[0]))  //�жϲ���
        {
        case 1:   //add file
        case 2:     //cp
        case 3:     //ls
        //��ӡ���л�ûд����Ϊ���÷�ʽûȷ��
            list_files_name_only(curNode);
            break;
        case 4:     //list
            list_files(curNode);
            break;
        case 5:     //cd
            scanf("%s", command[1]);
            strcpy(ch, curNode->info->path);

            if (locate_node())
            break;
        case 7:     //tree
            tree_files_in_path(argv[0]);
            break;
        case 9:     //open
            scanf("%s", command);   //Ҫ�򿪵�·��
            free_tree(root);        //�ͷ�֮ǰ�򿪵���
            if (!folder_exsists(command))   //�ļ��в�����
            {
                printf("%��ʧ�ܣ�%s�����ļ��С�", command);
                break;
            }
            curNode = root = create_files_bitree(command);
            break;
        case 0:
            printf("\n");
        case -1:    //��ƥ��
        default:
            printf("��Ч����\n");
            break;
        }
    }
    return 0;
}

int get_case_key(char *option)
{
    if (0 == strlen(option))
        return 0;
    if (0 == strcmp("add" ,option))
        return 1;
    else if (0 == strcmp("cp", option))
        return 2;
    else if (0 == strcmp("ls", option))
        return 3;
    else if (0 == strcmp("list", option))
        return 4;
    // else if (0 == strcmp("mv", option))
    //     return 5;
    // else if (0 == strcmp("rm", option))
    //     return 6;
    else if (0 == strcmp("tree", option))
        return 7;
    // else if (0 == strcmp("mkdir", option))
    //     return 8;
    else if (0 == strcmp("open", option))
        return 9;
    else
        return -1;
}