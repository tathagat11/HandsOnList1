/*===================================================================
Name: 27b.c
Author: Tathagata Talukdar
Description: Run ls -Rl command using execlp.
Date: 5th Sep, 2023
=====================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    if(execlp("ls", "ls", "-Rl", NULL) == -1){
        perror("Failure!\n");
        return(EXIT_FAILURE);
    }
    else {
        printf("Success!\n");
    }
    return 0;
}