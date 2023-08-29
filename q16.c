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
	errExit("Error1");
    }
    if ((fd = open("textfile2.txt", O_RDWR)) == -1) {
        perror("open");
        exit(1);
    }
    printf("Press Enter to get lock: ");
    getchar();
    printf("Trying to get lock...");
    if (fcntl(fd, F_SETLKW, &file_lock) == -1) {
        perror("fcntl");
        exit(1);
    }
    printf("got lock\n");
    printf("Press Enter to release lock: ");
    getchar();
    file_lock.l_type = F_UNLCK;  /* set to unlock same region */
    if (fcntl(fd, F_SETLK, &file_lock) == -1) {
        perror("fcntl");
        exit(1);
    }
    printf("Unlocked.\n");
    close(fd);
}