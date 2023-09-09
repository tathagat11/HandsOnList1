/*=======================================================
Name: 11c.c
Author: Tathagata Talukdar
Description: Use fcntl to duplicate fd.
Date: 5th Sep, 2023
=======================================================*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int fd;
	fd = open("textfile1.txt",O_RDWR|O_APPEND);
	if(fd == -1)
		printf("Error \n");
	write(fd,"Opened from fd",strlen("Opened from fd"));
	int fd2 = fcntl(fd,F_DUPFD);
	write(fd2,"This is from fcntl",strlen("This is from fcntl"));
	return 0;
}