/*===================================================================
Name: 27d.c
Author: Tathagata Talukdar
Description: Run ls -Rl command using execv.
Date: 5th Sep, 2023
=====================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char *my_command[] = {"ls", "-Rl", NULL};
    if(execv("/bin/ls", my_command) == -1){
        perror("Failure!\n");
        return(EXIT_FAILURE);
    }
    else {
        printf("Success!\n");
    }
    return 0;
}