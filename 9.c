/*=======================================================
Name: 9.c
Author: Tathagata Talukdar
Description: Print stats of a file.
Date: 7th Sep, 2023
=======================================================*/

#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

void sfile(char const fileName[]);
char *formatdata(char * str , time_t val);
int main()
{
	size_t rd;
	char* buffer = 0;
	size_t buffer_size = 0;

	printf("Enter the name of a file to check: \n");
	rd = getline(&buffer,&buffer_size,stdin);

	if(rd <=0 ){
		printf("getline failed\n");
		exit(1);
	}

	if(buffer[rd-1] == '\n'){
		buffer[rd-1] = 0;
	}

	int s = open(buffer,O_RDONLY);
	if(s==-1){
		printf("File doesn't exist\n");
		exit(1);
	}
	else
	{
		sfile(buffer);
	}
	free(buffer);
	return 0;
}

char * formatdata(char *str, time_t val){
	strftime(str,36,"%d.%m.%Y %H:%M:%S",localtime(&val));
	return str;
}

void sfile(char const fileName[]){
	struct stat sfile;
	if(stat(fileName,&sfile)==-1){
		printf("Error Occured\n");
	}

	char date[36];
	// Accessing data mumber of stat struct
	printf("\nFile inode number : %ld",sfile.st_ino);
	printf("\nNumber of hard links: %ld",(unsigned int)sfile.st_nlink);
	printf("\nUID : %ld",sfile.st_uid);
	printf("\nGID : %ld",sfile.st_gid);
	printf("\nSize : %ld",sfile.st_size);
	printf("\nBlock size : %ld",sfile.st_blksize);
	printf("\nNumber of blocks : %ld",sfile.st_blocks);
	printf("\nTime of last access : %s",formatdata(date,sfile.st_atime));
	printf("\nTime of last change : %s",formatdata(date,sfile.st_ctime));
	printf("\nTime of last modification : %s",formatdata(date,sfile.st_mtime)); 
	printf("\n");
}