#include "NodeOpe.c"
//����NodeOpe.c�ļ��ﺯ����ȷ??
//Author:л��??
//2019.12.11
int main()
{
	char *path2 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS\\test_NodeOpe.c"; //�ļ�
	char *path1 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS"; //�ļ���
// ����get_name()����
	char *name  = get_name(path1);
	printf("name = %s\n", name);

//	����get_extension()����
	char *extension = get_extension(path1);
	printf("extension = %s\n", extension);

//	����get_file_size()����
	long int size  = get_file_size(path1);
	printf("size = %ldByte, %s\n", size, get_size_string(size));

//	����file_exsists()����
	printf("if file exsists? %d\n", file_exsists(path1));

//	����folder_exsists()����
	printf("if folder exsists? %d\n\n", folder_exsists(path1));

//	����create_info_node()����
	FileInfo * head =  create_info_node(path1);
	printf("type: %d\n", head->type);
	printf("name: %s\n", head->name);
	printf("path: %s\n", head->path);
	printf("timeNum:  %ld\n", head->modifyTimeNum);
	printf("time: %s\n", head->modifyTime);
	printf("size: %ld\n", head->size);
	printf("extension: %s\n", head->extension);
	printf("innerFileNum: %d\n", head->innerFileNum);

	system("pause");
	return 0;
}
