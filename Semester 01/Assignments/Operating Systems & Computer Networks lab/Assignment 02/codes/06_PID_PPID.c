#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int pid;
    pid= fork();
    if (pid==-1){
        perror("Fork failed -.-");
        exit(0);
    }

    if (pid==0){
        printf("\n1.1 Child Process is under execution\n");
        printf("\n1.2 PID of Child Process is [%d].\n", getpid());
        printf("\n1.3 PID of Parent Process is [%d].\n", getppid());

    }else{
        printf("\n2.1 Parent Process is under execution\n");
        printf("\n2.2 PID of Parent Process is [%d].\n", getpid());
        printf("\n2.3 PID of GrandParent Process is [%d].\n", getppid());
    }
}