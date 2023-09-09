/*=======================================================
Name: 14.c
Author: Tathagata Talukdar
Description: Find the file type.
Date: 5th Sep, 2023
=======================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	if(argc !=2){
		return 1;
	}

	const char* filename=argv[1];

	struct stat fstat;
	if(stat(filename, &fstat)==-1){
		perror("error getting file information");
		return 1;
	}
	// printf("%d", fstat.st_mode);
	if(S_ISREG(fstat.st_mode)){
		printf("%s is a regular file. \n", filename);
	}
	else if (S_ISDIR(fstat.st_mode)){
		printf("%s is a directory.\n", filename);
	}
	else if(S_ISLNK(fstat.st_mode)){
		printf("%s is a symbolic link.\n", filename);
	}
	else if(S_ISFIFO(fstat.st_mode)){
		printf("%s is a FIFO/pipe.\n", filename);
	}
	else if(S_ISSOCK(fstat.st_mode)){
		printf("%s is a socket.\n", filename);
	}
	else if(S_ISBLK(fstat.st_mode)){
		printf("%s is a block special file.\n" , filename);
	}
	else if(S_ISCHR(fstat.st_mode)){
		printf("%s is a charcter special file.\n" , filename);
	}
	else{
		printf("%s is of an unknown type.\n" , filename);
	}
	return 0;
}