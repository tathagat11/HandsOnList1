/*===================================================================
Name: 21.c
Author: Tathagata Talukdar
Description: To create a child process using 
Date: 5th Sep, 2023
=====================================================================*/
#include <stdio.h>
#include <sys/types.h>
/*===================================================================
Name: 21.c
Author: Tathagata Talukdar
Description: To create a child process using fork()
Date: 5th Sep, 2023
=====================================================================*/
#include <unistd.h>

int main(){
    if(fork()){
        printf("This is from parent process with PID: %d\n", getpid());
    } 
    else{
        printf("This is from child process with PID: %d whose parent process is: %d\n", getpid(), getppid());
    }   
}