/*===================================================================
Name: 30.c
Author: Tathagata Talukdar
Description: Run a shell script at a specified time.
Date: 5th Sep, 2023
=====================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main(){
    struct tm runTime = {0};
    runTime.tm_hour = 23;   
    runTime.tm_min = 33;     
    runTime.tm_sec = 0;     
    time_t now = time(NULL);
    struct tm scheduledTime = *localtime(&now);
    scheduledTime.tm_hour = runTime.tm_hour;
    scheduledTime.tm_min = runTime.tm_min;
    scheduledTime.tm_sec = runTime.tm_sec;
    if (difftime(mktime(&scheduledTime), now) <= 0) {
        scheduledTime.tm_mday++;  
    }
    time_t timeDiff = difftime(mktime(&scheduledTime), now);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid > 0) {
        printf("Daemon PID: %d\n", pid);
        return EXIT_SUCCESS;
    }
    sleep(timeDiff);
    system("./1.sh");

    return EXIT_SUCCESS;
}