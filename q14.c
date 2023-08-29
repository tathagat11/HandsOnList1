#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	if(argc !=2){
		printf("usage: %s <filename>\n", argv[0]);
		return 1;
	}

	const char* filename=argv[1];

	struct stat file_status;
	if(stat(filename, &file_status)==-1){
		perror("error getting file information");
		return 1;
	}

	if(S_ISREG(file_status.st_mode)){
		printf("%s is a regular file. \n", filename);
	}
	else if (S_ISDIR(file_status.st_mode)){
		printf("%s is a directory.\n", filename);
	}
	else if(S_ISLNK(file_status.st_mode)){
		printf("%s is a symbolic link.\n", filename);
	}
	else if(S_ISFIFO(file_status.st_mode)){
		printf("%s is a FIFO/pipe.\n", filename);
	}
	else if(S_ISSOCK(file_status.st_mode)){
		printf("%s is a socket.\n", filename);
	}
	else if(S_ISBLK(file_status.st_mode)){
		printf("%s is a block special file.\n" , filename);
	}
	else if(S_ISCHR(file_status.st_mode)){
		printf("%s is a charcter special file.\n" , filename);
	}
	else{
		printf("%s is of an unknown type.\n" , filename);
	}
	return 0;
}