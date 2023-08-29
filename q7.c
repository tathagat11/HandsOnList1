#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc , char* argv[]) {
	
	if(argc != 3)
	{
		printf("You are useless");
		return 0;	
	}
	int fdr = open(argv[1],O_RDONLY);
	int fdw = open(argv[2],O_WRONLY|O_CREAT);
	if(fdr == -1 || fdw == -1)
		printf("Do Nothing\n");

	while(1)
	{
		char buffer;
		int char_read = read(fdr,&buffer,sizeof(buffer));
		if(char_read == 0)
			break;
		int char_writtern = write(fdw,&buffer,1);
	}
	int fd_read_close = close(fdr);
	int fd_write_close = close(fdw);
	if(fd_read_close == -1 || fd_write_close == -1)
		printf("Unable to close");
	return 0;
}