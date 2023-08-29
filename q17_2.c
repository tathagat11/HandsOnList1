#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int fd;
    fd = open("textfile3.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    struct flock file_lock = {F_WRLCK, SEEK_SET, 0, 0, 0};
    file_lock.l_type = F_WRLCK;
    file_lock.l_pid = getpid();
    printf("Press enter to get lock");
    getchar();
    if (fcntl(fd, F_SETLKW, &file_lock) == -1) {
        perror("fcntl");
        exit(1);
    }
    char buff1[20];
    int bytesRead = read(fd, buff1, sizeof(buff1));
    if (bytesRead <= 0) {
        perror("Error reading from file");
        close(fd);
        return 1;
    }
    int currentTicket = atoi(buff1);
    printf("Current ticket number: %d\n", currentTicket);
    lseek(fd, 0, SEEK_SET);
    snprintf(buff1, sizeof(buff1), "%d\n", currentTicket + 1);
    ssize_t br;
    br = write(fd, buff1, strlen(buff1));
    if(br == -1){
        perror("Error in writing to the file");
        exit(1);
    }
    printf("Press enter to release lock");
    getchar();
    file_lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &file_lock) == -1) {
        perror("fcntl");
        exit(1);
    }
    close(fd);
    return 0;
}