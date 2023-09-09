/*=======================================================
Name: 17a.c
Author: Tathagata Talukdar
Description: Ticket reservation system using file lock (write).
Date: 5th Sep, 2023
=======================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    int fd;
    fd = open("textfile5.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd == -1) {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }
    struct flock file_lock = {F_WRLCK, SEEK_SET, 0, 0, 0};
    file_lock.l_type = F_WRLCK;
    file_lock.l_pid = getpid();
    printf("Press enter to get lock");
    getchar();
    if (fcntl(fd, F_SETLKW, &file_lock) == -1) {
        printf("Error setting lock\n");
        return EXIT_FAILURE;
    }
    int tkt;
    char buff1[20];
    printf("Enter the ticket number - ");
    scanf("%d", &tkt);
    snprintf(buff1, sizeof(buff1), "%d\n", tkt);
    ssize_t br;
    br = write(fd, buff1, strlen(buff1));
    if(br == -1){
        printf("Error writing to file.\n");
        return EXIT_FAILURE;
    }
    printf("Ticket reserved. Your ticket number is: %d\n", tkt);
    printf("Press enter to release lock");
    getchar();
    getchar();
    file_lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &file_lock) == -1) {
        printf("Error unlocking file.\n");
        return EXIT_FAILURE;
    }
    close(fd);
    return 0;
}