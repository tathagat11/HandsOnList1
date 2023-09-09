/*===================================================================
Name: 29.c
Author: Tathagata Talukdar
Description: View and set priority.
Date: 5th Sep, 2023
=====================================================================*/
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid = getpid();

    int current_policy = sched_getscheduler(pid);
    printf("%d\n",current_policy);
    if(current_policy == -1){
        perror("Error: ");
        return EXIT_FAILURE;
    }
    printf("Current Scheduling Policy: ");
    switch (current_policy)
    {
        case SCHED_FIFO:
            printf("FIFO scheduling.\n");
            break; 
        
        case SCHED_RR:
            printf("Round Robin.\n");
            break;
        
        case SCHED_BATCH:
            printf("Batch Scheduling.\n");
            break;
        
        case SCHED_DEADLINE:
            printf("Deadline Schediling.\n");
            break;
        
        case SCHED_IDLE:
            printf("CPU Idle Scheduling.\n");
            break;
        
        case SCHED_OTHER:
            printf("Other Scheduling (default).\n");
            break;

        default:
            printf("Unknown Scheduling.\n");
            break;
    }

    struct sched_param param;
    // param.sched_priority = 99; set to fifo works with root/sudo

    if(sched_setscheduler(pid, SCHED_OTHER, &param) == -1){
        perror("Error setting priority.\n");
        return EXIT_FAILURE;
    }
    printf("Changed priority to default scheduling.\n");
    return EXIT_SUCCESS;
}