/*===================================================================
Name: 24.c
Author: Tathagata Talukdar
Description: Make a child process go into orphan state.
Date: 5th Sep, 2023
=====================================================================*/
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    if(fork()==0){
        printf("Child PID: %d\n", getpid());
        sleep(100);
        printf("Child awake\n");
    }
    else{
        printf("Parent PID: %d\n", getpid());
        exit(0);
    }
    return 0;
}