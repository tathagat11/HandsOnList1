#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	
	fd_set checkfds;
	struct timeval to;
	FD_ZERO(&checkfds);
	FD_SET(0, &checkfds);
	to.tv_sec=10;
	to.tv_usec=0;
	int rs=select(1,&checkfds,NULL,NULL,&to);
	if(rs<0){
		perror("Select");
		exit(1);
	}
	else if(rs == 0){
		printf("No data.\n");
		exit(1);
	} else if(rs > 0){
		printf("Data available\n");
		exit(1);
	}
	return 0;
}