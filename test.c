#define _CRT_SECURE_NO_WARNINGS 1



#include"comment_covert.h"

int main()
{
	FILE *fRead = NULL;
	FILE *fWrite = NULL;
	printf("*****注释转换开始******\n");
	fRead = fopen(READFILENAME, "r");
	if (NULL == fRead)
	{
		perror("read of file");
		exit(EXIT_FAILURE);
	}
	
	fWrite = fopen(WRITEFILENAME, "w");
	if (NULL == fRead)
	{
		fclose(fRead);
		perror("write of file");
		exit(EXIT_FAILURE);
	}
	CommentConvert(fRead, fWrite);
	printf("*****注释转换结束******\n");
	fclose(fRead);
	fclose(fWrite);
	system("pause");
	return 0;
}