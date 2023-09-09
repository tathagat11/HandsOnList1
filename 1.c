/*=======================================================
Name: 1.c
Author: Tathagata Talukdar
Description: Use soft link, hard link and fifo file
Date: 5th Sep, 2023
=======================================================*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
        int sl = symlink("textfile1.txt","destSL");
        if(sl<0)
                {perror("Failed");return 1;}
        int hl = link("textfile1.txt","destHL");
        if(hl<0)
                {perror("Failed"); return 1;}
        int nod = mknod("destFIFO",S_IFIFO,0);
        if(nod<0)
                perror("Failed");
        return 0;
}