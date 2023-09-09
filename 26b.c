
//INCOMPLETE!!!

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    char *command = "./a.out ";
    printf("Enter Input: ");
    char *input1;
    scanf("%s", input1);
    if(execl("a.out", command, input1, NULL) == -1){
        perror("Failure!\n");
        return(EXIT_FAILURE);
    }
    else {
        printf("Success!\n");
    }
    return 0;
}