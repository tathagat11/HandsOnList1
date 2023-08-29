#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

struct items{
  int id;
  char name[20];
  int item_price;
};

void main() {
  struct flock flock;
  int fd=open("data.txt", O_CREAT | O_RDWR, 0777);
  struct items item1, item2, item3;
  item1.id=1;
  item2.id=2;
  item3.id=3;
  strcpy(item1.name, "ab");
  strcpy(item2.name, "cd");
  strcpy(item3.name, "ef");
  item1.item_price=199;
  item2.item_price=500;
  item3.item_price=1999;
  write(fd, &item1, sizeof(struct items));
  flock.l_type=F_WRLCK;
  flock.l_whence = SEEK_SET;
  flock.l_start = 8;
  flock.l_len = 8;
  flock.l_pid = getpid();
  fcntl(fd,F_SETLKW , &flock);
  printf("Entered critical section...\n");
  printf("Press enter to unlock...\n");
  getchar();
  printf("Write lock unset...\n");
  flock.l_type=F_RDLCK;
  flock.l_start=0;
  flock.l_len=8;
  fcntl(fd, F_SETLKW, &flock);
  printf("Read lock set...\n");
  flock.l_type=F_UNLCK;
  flock.l_start=8;
  flock.l_len=8;
  fcntl(fd, F_SETLKW, &flock);
  printf("Press enter to exit...\n");
  getchar();
  printf("Read lock unset...\n");
  close(fd);
}