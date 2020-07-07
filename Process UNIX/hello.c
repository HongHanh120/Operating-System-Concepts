#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    pid = fork();
    pid = fork();
    printf("Hello, pid = %d\n", getpid());

    return 0;
}