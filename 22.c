/*===================================================================
Name: 22.c
Author: Tathagata Talukdar
Description: Write to a file from parent and child process.
Date: 5th Sep, 2023
=====================================================================*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(){
    int fd = open("textfile3.txt", O_WRONLY);
    if(fork()){
        char buffer[10]="1234567890";
        write(fd,buffer,sizeof(buffer));
        close(fd);
    }
    else{
        char buffer[10]="0987654321";
        write(fd,buffer,sizeof(buffer));
        close(fd);
    }
    return 0;
}