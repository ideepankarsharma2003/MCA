#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int pid;
    pid= fork();
    if (pid==-1){
        perror("fork failed");
        exit(0);
    }

    else if (pid==0){
        printf("\n1.1 Child process is under execution");
        printf("\n1.2 Process ID of Child process is [%d]", getpid());
        printf("\n1.3 Process ID of Parent process is [%d]\n", getppid());
    }
    else{
        printf("\n2.1 Parent process is under execution");
        printf("\n2.2 Process ID of Parent process is [%d]", getpid());
        printf("\n2.3 Process ID of Parent process is [%d]\n", getppid());

    }
    return 0;
}