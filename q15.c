#include<stdio.h>

extern char **environment1;

void main() {
  for(size_t i=0; environment1[i]!=NULL; i++)
    printf("%s\n", environment1[i]);
}