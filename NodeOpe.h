#ifndef _NODEOPE_H
#define _NODEOPE_H


/*
 * ���ã������ļ�(��)���������һ��'\'��ʼ��ĩβ
 * �÷�������path���ļ��ľ���·�����ļ������ڷ���NULL
 */
char * get_name(char * path);


/*
 * �����ļ�����չ����û����չ���ͷ���NULL
*/
char * get_extension(char *path);


/*
 * ���ã������ļ��Ĵ�С����λΪByte(�ֽ�)
 * �÷�������str���ļ���·�����ļ������ڷ���-1
 */
long get_file_size(char *str);


/*
 * ʹ�÷�ʽ������һ���ļ��ľ���·��path����������ļ���FileInfo�ڵ㡣ע��ʹ��ǰҪ�ж��Ƿ�ΪNULL
 * ʵ��Ҫ��
 *      1.���ж�path�Ƿ�Ϊ�ļ��л򲻴��ڣ��ǵĻ�ֱ�ӷ���NULL
 *      2.�ɵ��������Ѿ�д�õĺ������ڵ��������Ϣ��Ҫ��ȡ
*/
FileInfo * create_info_node(char *path);


boolean is_file_node(FileNode *node);    //����ڵ������ļ��򷵻�true�����򷵻�false
boolean is_folder_node(FileNode *node);  //���ļ����򷵻�true�����򷵻�false
boolean file_exsists(char *path);   //��path�����ڻ������ļ��У�����false
boolean folder_exsists(char *path); //��path�����ڻ����ļ�������false


/*
 * ���ã���spacing����������name������spacing���ַ��ر��ض�
*/
void print_name(char *name, int spacing);


/*
 * ���ã��ͷ�һ�������ڴ�
 * ������֪���������������Ҫ��FilesBiTree��NULL
*/
void free_tree(FilesBiTree tree);

/*
 * ���ã�ǰ���������ļ��������ڵ��name
*/
void pre_order_in_name(FilesBiTree root)��




//�����������ûʲô��
// /*
//  * �����ļ����ڵ�·��
//  * ע��Ҫ�ö�̬�ڴ�
//  */
// char * get_dir(char * path);
#endif