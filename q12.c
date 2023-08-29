#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd = open("textfile1.txt",O_RDWR|O_APPEND);
	int flg = fcntl(fd,F_GETFL);
	if(flg==-1)
		exit(1);
	printf("Get file descriptor flags (F_GETFD) %d\n",flg);
	return 0;
}