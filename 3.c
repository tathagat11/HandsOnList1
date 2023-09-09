/*=======================================================
Name: 3.c
Author: Tathagata Talukdar
Description: Create file descriptor with creat() and print it.
Date: 5th Sep, 2023
=======================================================*/
#include<stdio.h>
#include<fcntl.h>
int main()
{
	int file_desc = creat("textfile4.txt",0777);
	printf("File Descriptor Value : %d.\n",file_desc);
	return 0;
}