#include"NodeOpe.c"
//����NodeOpe.c�ļ��ﺯ����ȷ??
//Author:л��??
//2019.12.11
int main()
{
	char *path1 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS\\test_NodeOpe.c"; //�ļ�
	char *path2 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS"; //�ļ�??
	char *path3 = "E:\\CC\\Code\\From_GitHub\\Xin-Yue\\�ֳ�?_?���������ĵ�ͬѧ��Լ̸�¼�.png";
// ����get_base_name()����
	char *name  = get_base_name(path3);
	printf("%s\n", name);

//	����get_extension()����
	char *extension = get_extension(path3);
	printf("%s\n", extension);

//	����get_file_size()����
	long int size  = get_file_size(path3);
	printf("%ld\n", size);

//	����get_file_status()����
	// get_file_status(path3);

//	����file_exsists()����
	printf("%d\n", file_exsists(path3));

//	����folder_exsists()����
	printf("%d\n", folder_exsists(path3));

//	����get_dir()����
	printf("%s\n", get_dir(path3));


//	����create_info_node()����
	// FileInfo * head =  create_info_node(path3);
	// printf("type: %d\n", head->type);
	// printf("basename: %s\n", head->baseName);
	// printf("path: %s\n", head->path);
	// printf("timeNum:  %ld\n", head->modifyTimeNum);
	// printf("time: %s\n", head->modifyTime);
	// printf("size: %ld\n", head->size);
	// printf("extension: %s\n", head->extension);
	// printf("innerFileNum: %d\n", head->innerFileNum);

	system("pause");
	return 0;
}
