/*=======================================================
Name: 15.c
Author: Tathagata Talukdar
Description: Print the environment variable of user.
Date: 5th Sep, 2023
=======================================================*/
#include<stdio.h>

int main(int argc, char *argv[], char *env_user[]){
  for(int i = 0; env_user[i]!=NULL; i++){
    printf("%s\n", env_user[i]);
  }
  printf("\n");
  return 0;
}