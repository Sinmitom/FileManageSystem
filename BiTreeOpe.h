/*
 * time��2019��12��7�� 11��38��
 * autho���δ�
 * �����������˶Դ洢�ļ��Ķ������ĸ��ֲ�����
 *      ������Ӧֻ���Ⱪ¶��Щ�����������������ڲ�ʵ�֡�
 *      �����GUIʱ�������п���ʱҲӦֻ������Щ������
 */

/*modify: л���*/
//ʵ�����ͷ�ļ�ʱ��Ҫ����InfoOpe.h������ʹ������ĺ���


#ifndef BITREEOPE_H
#define BITREEOPE_H

#include "NodeInfo.h"
#include "State.h"

// û�������������Ҫ����2����������
// /*
//  * ʵ�ֹ��ܣ��ֱ��path�õ���֮��Ӧ��FileNode�ʹ�FileNode�õ���Ӧ��path
//  *
// */
// FileNode * get_node_from_path(char *path);
// char * get_path_from_node(FileNode *node);

/*
 * ��������������pathĿ¼�µĶ�����
 * ʵ��Ҫ��
 *      1. ���������ֵܷ��洢�ڵ�
 *      2. Ӧ���жϴ�path�Ƿ�Ϊ�գ���Ϊ�գ�ֱ�ӷ���NULL
 *      3. �ݹ鴴����pathĿ¼�µ������ļ��еĽڵ�
 *      4. �ɵ���creat_node����
 */
FilesBiTree create_files_bitree(char *path);



/*
 * ʵ�ֹ��ܣ���node�ļ������½�һ������ΪfileName���ļ�
 * ʵ��Ҫ��
 *      1. ���node�Ƿ�Ϊ�ļ��У����fileName�Ƿ��Ѵ���
 *      2. ���½�ʵ�ʵ��ļ����ٴ������ļ��������ڵ㣬�ѽڵ�嵽node������
 */
int add_file(FileNode *node, char *fileName);
int add_file_in_path(char *path, char *fileName);



/*
 * ʵ�ֹ��ܣ���node�ļ������½�һ����ΪfolderName���ļ���
 * Ҫ��ͬ��
*/
int add_folder(FileNode *node, char *folderName);
int add_folder_in_path(char *path, char *folderName);



/*
 * �������ͣ�OK��ʾ�ɹ�ִ�У�ERROR��ʾִ��ʧ��
 * ʵ�ֹ��ܣ���ӡ��Ŀ¼�µ��ļ�(��)���ο���powerShell��ʹ��tree�����Ч��
 * ʵ��Ҫ��
 *          1. Ҫ���жϽ��յ������ļ������ļ���
 *          2. ���ļ���Ϊ�գ���ֱ�ӷ���
 *          3. �ݹ���ã�������ļ����µ������ļ�(��)
 */
int tree_files(FilesBiTree tree);
int tree_files_in_path(char *path);   //����ͬ�ϣ�����·����Ϊ�������ɵ���print_files����



/*
 * ʵ�ֹ��ܣ�ֻ�����Ŀ¼�µ��ļ�(��)������
 * ʵ��Ҫ��
 *          1. Ҫ���жϽ��յ������ļ������ļ��С�
 *          2. ���ļ���Ϊ�գ���ֱ�ӷ���
 *          3. ֻ��ӡ���֣�һ�����6��
 *          5. **һ��Ҫ���룬���ж�Ҫ�������
 *              ˼·�����ҵ�����ַ����ĳ��ȣ��Դ˳�����Ϊ�����еĳ��ȣ�
 *              ͬʱ��������ȳ���ĳ��ֵ���������ֵ���ַ���ֱ�ӽص�
 *          4. �ɵ���sort_nodes_by_name()�������ļ���������
 */
int list_files_name_only(FilesBiTree tree);
int list_files_name_only_in_path(char *path); //����ͬ�ϣ�����·����Ϊ�������ɵ������Ϻ���



/*
 * ʵ�ֹ��ܣ���һ�������һ���ļ�(��)���ļ�(��)������С��ʱ��
 * ʵ��Ҫ��
 *      1. �ж��ǲ����ļ��У�Ϊ���ļ���ֱ�ӷ���
 *      2. �����м�Ҫ���룬�ο���PowerShell��ls�������ʽ
 */
int list_files(FilesBiTree tree);
int list_files_in_path(char *path);



/*
 * ���ѣ�
 * ������������ָ���ļ����²�����������name���ļ�(��)��
 *          ���ѽڵ��ָ��洢��һ��ֻ������(����)�У���UI����ʾ����Ҫ����ָ��
 * �ѵ㣺Ҫʹ�ö���ָ��
 * �Ż���Ч�ʿ��ܻ�ܵͣ�������취��һ������
*/
FileNode **find(FileNode * dir, char *name);



/*
 * ������������dirPath�ļ����²�����������name���ļ�(��)��
 *          ����lsһ����ӡ����ϸ��Ϣ����Ļ��
*/
int find_and_list(char * dirPath, char *name);



/*
 * ʵ�ֹ��ܣ��޸Ĵ�FileNode��Ӧ�ļ�(��)�����֣�����Ҫ�����ϵͳ���޸ģ���Ҫ�Դ��ļ���ʵ�������޸�
 * ����Ҫ��
 *      1. �޸Ķ������д洢����Ϣ
 *      2. �޸�ʵ���ļ���Ϣ
 *      3. Ҫ���½ڵ����Ϣ�������޸�ʱ����һ��
*/
int rename_file(FileNode *node, char *newName);
int rename_file_in_path(char *path, char *newName);



/*
 * ������֪�����ô˺���ʱ��Ҫ�ȴ�����丸�ڵ����亢�ӵĹ�ϵ��
 *          ͬʱ���ڵ���Ҫ��ʾ�û�ȷ��ɾ��
 * ʵ�ֹ��ܣ���nodeָ��Ŀռ�free������ʵ���ļ�ɾ��
 *          ʵ���߲��ù����Һ��ӣ����ǵ����߸ù��ĵġ�
 * ʵ��Ҫ��
 *      1.�ж����ļ������ļ��У������ļ���ֱ�ӷ���
 *      2.��Ҫɾ���Ľڵ�Ķ�̬�ڴ�free��
 *      3.ɾ���������Ľڵ�
 *      4.ɾ��ʵ���ļ�����Ȩ�޲����������
*/
int remove_file(FileNode *node);
int remove_file_in_path(char *path);



/*
 * ������֪�����ô˺���ǰ��Ҫ�����Һ��Ӹ����丸��ָ�������Ǹ����ӣ�(�������ֵܷ��洢)
 *          ɾ��ǰҪ�û�ȷ�ϡ�
 * ʵ�ֹ��ܣ�ɾ�����ļ����µ������ļ���ѭ��free�ڵ㡣
 * ʵ��Ҫ��
 *      1.�ж����ļ��л����ļ������ļ���ֱ�ӷ���
 *      2.free�����ж�̬�ڴ�
 *      3.ɾ���˽ڵ�����Ӽ������к���(���Һ��Ӻ�����ͬһ��������ļ�)
*/
int remove_folder(FileNode *node);
int remove_folder_in_path(char *path);



/*
 * ʵ�ֹ��ܣ����ƹ���
 * ʵ�ֲ��裺
 *      1. �ж�destPath�Ƿ�Ϊ���ڵ��ļ���
 *      2. ��nodeΪfolder�ͣ�����copy_folder�������������copy_file
*/
int copy_node(char *destPath, FileNode * node);
//�Ѿ���·��ΪsourcePath���ļ�(��)���Ƶ�destPath�ļ����£�ʵ��ͬ�ϣ�
//��sourcePath����Ϊ��Ӧ��node��������û���򷵻ش������ERROR
int copy_node_in_path(char *destPath, char *sourcePath);



/*
 * ʵ�ֹ��ܣ���nodeָ��Ľڵ㸴�Ƶ�Ŀ��·��destPath��
 * ʵ��Ҫ��
 *      1. ��node�ӵ�destPath�����ӣ��������ӵ��Һ�����
 *      2. ʵ�ʵ��ļ����Ʋ���
*/
int copy_file(char * destPath, FileNode *node);



/*
 * ʵ�ֹ��ܣ���nodeָ���Ŀ¼���Ƶ�destPath�£�
 *          ע������Ҫ����һ����Ŀ¼(�������µ������ļ�(��))��Ŀ��·��
 * ʵ��Ҫ��
 *      1. �ж�node�Ƿ�ΪĿ¼
 *      2.
*/
int copy_folder(char *destPath, FileNode *node);



/*
 * ������������node�ļ��ƶ���destPathĿ¼��
 * ʵϰҪ��
 *      1. �ж�destPath��node
 * ʵ��˼·������copy_file������remove_file����
*/
int move_file(char *destPath, FileNode *node);
int move_file_in_path(char *destPath, char *sourcePath);



/*
 * ʵ�ֹ��ܣ�ֻ��treeĿ¼�µ���һ���ļ���������ordering������ʽ��
 *          ��name��modifyTime��size����չ��(��չ�����ֵ����ţ���չ����ͬ��name��)��
 *          �Լ�������ķ�ʽ
 * ʵ��ϸ�ڣ�
 *      1. �ж�tree�Ƿ�Ϊ�ļ���
 *      2. ��tree������������
 * ʵ��˼·��������switch_case������ordering��������ת���ض�������ʽ����ȻҲ�������������õķ�����
 * �ѵ㣺Ŀǰ�����������ʵ��û��̫�õİ취������һ���ѵ㡣������ܸ��ô��룬ÿ����ʽ��дһ���㷨��
 *      �ټ����������ѡ������Ҫд8���㷨��������Щ�㷨ֻ���ж���������ͬ����ɴ������븴�á�
*/
void sort_files(FilesBiTree tree, char *ordering);
void sort_files_in_path(char *path);



#endif
