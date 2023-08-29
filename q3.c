#include<stdio.h>
#include<fcntl.h>
int main()
{
	int file_desc;
	file_desc = creat("textfile4.txt",0777);
	printf("File Descriptor Value : %d.\n",file_desc);
	return 0;	
}