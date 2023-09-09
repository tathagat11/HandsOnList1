/*=======================================================
Name: 8.c
Author: Tathagata Talukdar
Description: Read from a file and print it line by line.
Date: 5th Sep, 2023
=======================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(){
	int fd = open("tempfile.txt", O_RDONLY);
	if(fd == -1){
		perror("Couldnt open file!");
		return 1;
	}

	char buffer[BUFFER_SIZE];
	ssize_t readdata;

	while((readdata = read(fd, buffer, sizeof(buffer))) > 0){
		for(ssize_t i = 0; i < readdata; i++){
			putchar(buffer[i]);
		}
	}

	close(fd);

	if(readdata == -1){
		perror("Error reading file");
		return 1;
	}
	
	return 0;

}