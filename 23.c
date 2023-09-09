/*===================================================================
Name: 23.c
Author: Tathagata Talukdar
Description: Make a child process go into zombie state.
Date: 5th Sep, 2023
=====================================================================*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    if(fork()==0){
        printf("Child process PID: %d\n", getpid());
        exit(0);
    }
    else {
        printf("Parent process PID: %d\n", getpid());
        printf("Parent process asleep.\n");
        sleep(30);
        printf("Parent process awake.\n");
        while(1);
    }
    return 0;
}