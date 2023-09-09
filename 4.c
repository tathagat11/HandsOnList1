/*=======================================================
Name: 4.c
Author: Tathagata Talukdar
Description: Open and work with a file descriptor.
Date: 5th Sep, 2023
=======================================================*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(){
    int fd = open("./textfile4.txt", O_RDWR | O_CREAT | O_EXCL, 0666);
    if(fd==-1){
        if(errno == EEXIST) printf("The file already exists");
        else perror("Erroropening the file.");
    }
    else {
        printf("file opened successfully with O_EXCL flag.\n");
        char buffer[] = "hello\nthere.";
        if(write(fd, buffer, sizeof(buffer)-1) == -1){
            perror("Error writing to file.");
            close(fd);
            return 1;
        }
    }
    // char buffer2[100];
    // int readdata = read(fd, buffer2, sizeof(buffer2)-1);
    // if(readdata == -1){
    //     perror("Couldn't read.");
    //     close(fd);
    //     return 1;
    // }

    // buffer2[readdata] = '\0';
    // printf("File Content:\n %s", buffer2);

    close(fd);
    return 0;
}