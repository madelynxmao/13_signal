#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

static void sighandler(int signo){
    //Before exiting, append a message to a file noting that the program exited due to SIGINT
    if (signo == SIGINT){
        printf("Program exited due to SIGINT\n");
        exit(0);
    }
    //Print out the PID of the parent process, should not cause the program to exit.
    if (signo == SIGUSR1){
        printf("PID of parent process: getpid())\n");
    }
}


int main(){

    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    while(1){
        //Print out the process’ PID inside the loop.
        printf("Process PID: %d\n", getpid());
        sleep(1);
    }
    return 0;
}