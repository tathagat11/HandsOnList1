/*=======================================================
Name: 12.c
Author: Tathagata Talukdar
Description: Get file status using fcntl.
Date: 5th Sep, 2023
=======================================================*/
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd = open("textfile1.txt",O_RDWR|O_APPEND);
	int flg = fcntl(fd,F_GETFL);
	if(flg==-1)
		return 1;
	printf("The file mode is: %d\n",flg);
	return 0;
}