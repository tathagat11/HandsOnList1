#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int fd;
	fd = open("textfile1.txt",O_RDWR|O_APPEND);
	if(fd == -1)
		printf("Error \n");
	write(fd,"Opened from fd\n",strlen("Opened from fd\n"));
	int dupl = fcntl(fd,F_DUPFD);
	write(dupl,"This is from dupl\n",strlen("This is from dupl\n"));
	return 0;
}