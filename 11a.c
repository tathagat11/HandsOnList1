/*=======================================================
Name: 11a.c
Author: Tathagata Talukdar
Description: Use dup function.
Date: 5th Sep, 2023
=======================================================*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(){
    int fd = open("textfile1.txt", O_RDWR | O_APPEND);
    if(fd==-1){
        printf("Error opening file\n");
    }
    write(fd, "This is from fd", sizeof("This is from fd"));
    int fd2 = dup(fd);
    write(fd2, "This is from dup.", sizeof("This is from dup."));
    close(fd);
    close(fd2);
    return 0;
}