/*=======================================================
Name: 16.c
Author: Tathagata Talukdar
Description: Lock and unlock a file.
Date: 5th Sep, 2023
=======================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
    
int main(int argc, char *argv[])
{
    struct flock file_lock = {F_WRLCK, SEEK_SET, 0, 0, 0};
    int fd;
    file_lock.l_pid = getpid();
    if (argv[1][0] == 'r') 
    {
        file_lock.l_type = F_RDLCK;
    }
    else if (argv[1][0] == 'w') 
    {
        file_lock.l_type = F_WRLCK;
    }
    else
    {
	    printf("Wrong Input.");
        return EXIT_FAILURE;
    }
    if ((fd = open("textfile2.txt", O_RDWR)) == -1) {
        printf("Opened.\n");
        return EXIT_FAILURE;
    }
    printf("Press Enter to get lock: ");
    getchar();
    printf("Trying to get lock...");
    if (fcntl(fd, F_SETLKW, &file_lock) == -1) {
        printf("fcntl error.\n");
        return EXIT_FAILURE;
    }
    printf("got lock\n");
    printf("Press Enter to release lock: ");
    getchar();
    file_lock.l_type = F_UNLCK;  /* set to unlock same region */
    if (fcntl(fd, F_SETLK, &file_lock) == -1) {
        printf("fcntl error.\n");
        return EXIT_FAILURE;
    }
    printf("Unlocked.\n");
    close(fd);
}