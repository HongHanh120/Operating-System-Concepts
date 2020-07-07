#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int value = 5;
int main(){
    printf("Before fork()");
    pid_t pid;
    pid = fork();

    // error occurred
    if(pid < 0){
        fprintf(stderr, "\n Fork Faild");
        return 1;
    }
    // child process
    else if(pid == 0){
        value += 15;
        printf("\n CHILD: value = %d", value);
        /*LINE A*/
        printf("\n");
        return 0;
    }
    // parent process
    else if(pid > 0){
        wait(NULL);
        printf("\n PARENT: value = %d", value);
        /*LINE B*/
        printf("\n");
        return 0;
    }
} 