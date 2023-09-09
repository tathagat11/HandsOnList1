/*=======================================================
Name: 6.c
Author: Tathagata Talukdar
Description: Read and write onto terminal using read() & write()
Date: 5th Sep, 2023
=======================================================*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	char buffer[1024];
	read(0,&buffer,sizeof(buffer));
	write(1,&buffer,sizeof(buffer));
	return 0;
}