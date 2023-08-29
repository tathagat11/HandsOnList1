#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd,fd2,fd3,fd4,fd5; 
	fd = creat("text1.txt",0777);
	fd2 = creat("text2.txt",0777);
	fd3 = creat("text3.txt",0777);
	fd4 = creat("text4.txt",0777);
	fd5 = creat("text5.txt",0777);

	while(1)
	{}

	return 0;
}