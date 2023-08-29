#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fdr = open("tempfile.txt",O_RDONLY);
	if(fdr == -1)
	{
		printf("Unable to open the file\n");
		return 0;
	}

	while(1)
	{
		char ch;
		int rd = read(fdr,&ch,1);
		if(rd == 0)
			break;
		if(ch == "\n")
			printf("\n");
	}
	int fd_close = close(fdr);
	return 0;
}