/*===================================================================
Name: 20.c
Author: Tathagata Talukdar
Description: To change nice value and therefore priority of the process
Date: 5th Sep, 2023
=====================================================================*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>

int main(){
    int cur_nice;
    int pid = getpid();
    cur_nice = getpriority(PRIO_PROCESS, 0);
    printf("pid: %d, nice: %d\n", pid, cur_nice);
    getchar();
    nice(5);
    cur_nice = getpriority(PRIO_PROCESS, 0);
    printf("pid: %d, new nice: %d\n", pid, cur_nice);
    getchar();
    nice(-10); //--- DOES NOT WORK WITH USER ACCESS, only ROOT (use sudo)
    cur_nice = getpriority(PRIO_PROCESS, 0);
    printf("pid: %d, new nice: %d\n", pid, cur_nice);
    while(1);
    return 0;
}