/*===================================================================
Name: 26a.c
Author: Tathagata Talukdar
Description: Execute another executable program from this program.
Date: 5th Sep, 2023
=====================================================================*/
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

int main(){
    const char *command = "./a.out";
    int executeCommand = system(command);
    if(executeCommand == 0){
        printf("Success\n");
    }
    else {
        printf("Failure\n.");
    }
    
    return 0;
}