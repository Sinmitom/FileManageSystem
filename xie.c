#include"BiTreeOpe.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Maxsize 10  //�ļ��������10
#define Maxlen 50  //�ļ�������50
/*
 * ʵ�ֹ��ܣ���node�ļ������½�һ������ΪfileName���ļ�
 * ʵ��Ҫ��
 *      1. ����Ƿ�Ϊ�ļ��У����fileName�Ƿ��Ѵ���
 *      2. ���½��ļ����ٴ������ļ��������ڵ㣬�ѽڵ�嵽node������
 */
int new_file(FileNode *node , char *fileName)
{
	FILE *fp = NULL;






 }


/*
 * ��������������pathĿ¼�µĶ�����
 * ʵ��Ҫ��
 *      1. ���������ֵܷ��洢�ڵ�
 *      2. Ӧ���жϴ�path�Ƿ�Ϊ�գ���Ϊ�գ�ֱ�ӷ���NULL
 *      3. �ݹ鴴����pathĿ¼�µ������ļ��еĽڵ�
 *      4. �ɵ���creat_node����
 */


FilesBiTree create_files_bitree(char *path)
{
    if(path == NULL)   //��·��Ϊ�գ�����NULL
    {
        return NULL;
    }
    char fileName[Maxsize][Maxlen];  //·���µ�ÿһ���ļ���
	char *token;
	int i = 0;
	token = strtok(path, "\\"); //��ȡ����·����ÿһ����ļ���
    printf("%s", token);
    while(token!=NULL)
    {
        strcpy(fileName[i], token);
        token = strtok(NULL, "\\");
        printf("%s", token);
        printf("test\n");
        i++;
    }




    /*char drive[_MAX_DIR];
    char dir[_MAX_DRIVE];
    char fname[_MAX_FNAME];
    char ext[_MAX_EXT];
    _splitpath(path, drive,dir,fname, ext);
    printf("Drive:%s\n file name: %s\n file type: %s\n",drive,fname,ext);
    strcat(fname,ext);
    printf("File name with extension :%s\n",fname);
*/

}

int main()
{
	printf("hhh");
	char *path = "E:\\lava_answer\\lava\\lava\\experiment2\\t1\\test.txt";
	create_files_bitree(path);
	return 0;
}


