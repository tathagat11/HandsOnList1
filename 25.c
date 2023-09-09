/*===================================================================
Name: 25.c
Author: Tathagata Talukdar
Description: Make 3 child processes and wait for a particular child process.
Date: 5th Sep, 2023
=====================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int status;
    pid_t pid;
    int num_children = 3;
    for(int i = 0; i < num_children; i++){
        pid = fork();

        if(pid == 0){
            printf("Child %d (PID: %d) is running\n", i, getpid());
            sleep(2);
            printf("Child %d (PID: %d) is done\n", i, getpid());
            exit(0);
        }
    }
    printf("Parent (PID: %d) is waiting for child 2 (PID: %d) to finish\n", getpid(), getpid() + 2);
    pid_t waited_pid = waitpid(getpid() + 2, &status, 0);

    if(waited_pid == -1){
        perror("Wait Failed");
        exit(1);
    }
    if(WIFEXITED(status)){
        printf("Child 2 ended with status: %d\n",WEXITSTATUS(status));
    }
    return 0;
}