//Author:л���
//time��2019.12.12
//����BiTreeOpe.c�ļ��к�������ȷ�� 


#include"BiTreeOpe.c"


int main() 
{
	char *path1 = "D:\\����\\FileManageSystem";
	char *path2 = "D:\\����\\Java_answer\\java\\experiment2";
	char *path3 = "D:\\����\\FileManager\\test\\1";
	//����create_fil es_bitree()����
	FilesBiTree head = create_files_bitree(path3);
 	pre_order(head); 
	return 0; 
	
	
 } 
