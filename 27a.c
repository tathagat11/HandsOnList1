/*===================================================================
Name: 27a.c
Author: Tathagata Talukdar
Description: Run ls -Rl command using execl.
Date: 5th Sep, 2023
=====================================================================*/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    if(execl("/bin/ls", "ls", "-Rl", NULL) == -1){
        perror("Failure!\n");
        return(EXIT_FAILURE);
    }
    else {
        printf("Success!\n");
    }
    return 0;
}