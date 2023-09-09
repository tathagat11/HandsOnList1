/*=======================================================
Name: 11b.c
Author: Tathagata Talukdar
Description: Use dup2 function.
Date: 5th Sep, 2023
=======================================================*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(){
    int fd = open("textfile2.txt", O_RDWR | O_APPEND);
    if(fd==-1){
        printf("Error opening file\n");
    }
    write(fd, "This is from fd", sizeof("This is from fd"));
    int fd2;
    dup2(fd, fd2);
    write(fd2, "This is from dup2.", sizeof("This is from dup2."));
    close(fd);
    close(fd2);
    return 0;
}