/*=======================================================
Name: 7.c
Author: Tathagata Talukdar
Description: Read file and copy it onto a new file.
Date: 5th Sep, 2023
=======================================================*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc , char* argv[]) {
	if(argc != 3)
	{
		printf("You are useless");
		return 0;	
	}
	int fdr = open(argv[1],O_RDONLY);
	int fdw = open(argv[2],O_WRONLY|O_CREAT);
	if(fdr == -1 || fdw == -1)
		printf("Do Nothing\n");

	while(1)
	{
		char buffer;
		int char_read = read(fdr,&buffer,sizeof(buffer));
		if(char_read == 0)
			break;
		int char_writtern = write(fdw,&buffer,1);
	}
	close(fdr);
	close(fdw);
}