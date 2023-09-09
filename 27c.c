/*===================================================================
Name: 27c.c
Author: Tathagata Talukdar
Description: Run ls -Rl command using execle.
Date: 5th Sep, 2023
=====================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char *myEnv[] = {"MY_ENV_VARIABLE = custom_value", NULL};
    if(execle("/bin/ls", "ls", "-Rl", NULL, myEnv) == -1){
        perror("Failure!\n");
        return(EXIT_FAILURE);
    }
    else {
        printf("Success!\n");
    }
    return 0;
}