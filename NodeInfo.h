/*
 * Author: �δ�
 * Time: 2019��12��6�� 12��26��
 * �����������˽ڵ㡢���Ľṹ��
 */

#ifndef NODEINFO_H
#define NODEINFO_H

enum NodeType
{
    folder,  //folder��0
    file     //file��1
};

struct FileInfo
{
    enum NodeType type; //�ڵ�洢�����ͣ�folder��file
    char * path;        //�ļ�(��)����·������
    char *extension;    //>>��file��Ч<<���ļ�����չ(��׺)�����������򣬻���GUI��ʾ��ͬ��ͼ�꣬û������ΪNULL
    char * name;    //�ļ�(��)�����֣��ļ���������չ��
    char *modifyTime;   //���ַ����洢��ʱ��
    long modifyTimeNum; //��1970�굽���ڵ�����(���ߺ���)����������
    long size;          //�ļ�(��)��С����λ���ֽڡ��ļ�Ϊ�䱾���С���ļ���Ϊ���������ļ����ܴ�С
    int innerFileNum;   //>>��folder��Ч<<�����ļ�������һ����ļ�(��)������������Ϊ0�������ļ���������Ϊ-1
};
typedef struct FileInfo FileInfo;

struct FileNode
{
    struct FileInfo * info;
    struct FileNode * lch;  //����
    struct FileNode * rch;  //�Һ���
};
typedef struct FileNode FileNode;
typedef struct FileNode *FilesBiTree;



#endif