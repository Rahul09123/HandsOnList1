/*
============================================================================
Name : 30.c
Author : Rahul Raman
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 5th Sep 2025
============================================================================
*/

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    if(!fork()){
        setsid();
        chdir("/");
        umask(0);
            while(1){
                sleep(4);
                printf("Child PID: %d\n", getpid());
                printf("Daemon Process is running...\n");
            }

    }
    else exit(0);
}

/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program30$ cc 30.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program30$ ./a.out
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program30$ Child PID: 9784
Daemon Process is running...
Child PID: 9784
============================================================================
*/
