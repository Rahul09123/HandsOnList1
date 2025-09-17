/*
============================================================================
Name : execvp.c
Author : Rahul Raman
Description : Write a program to execute ls -Rl by the following system calls
                e. execvp
Date: 5th Sep 2025
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    int pid;

    printf("---Executing ls -Rl using execvp()---\n");
    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return 1;
    }
    if (pid == 0) { // Child process
        char *const argv[] = {"ls", "-Rl", NULL};
        execvp("ls", argv);
        perror("execvp failed");
        exit(1);
    } else { // Parent process
        wait(NULL);
    }
    return 0;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program30$ cc execvp.c 
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program30$ ./a.out
--- Executing ls -Rl using execvp() ---
.:
total 36
-rwxrwxr-x 1 asus asus 16224 Sep  5 19:08 a.out
-rw-rw-r-- 1 asus asus  1113 Sep  5 19:04 execl.c
-rw-rw-r-- 1 asus asus   885 Sep  5 19:06 execle.c
-rw-rw-r-- 1 asus asus   820 Sep  5 19:06 execlp.c
-rw-rw-r-- 1 asus asus   777 Sep  5 19:06 execv.c
-rw-rw-r-- 1 asus asus   555 Sep  5 19:08 execvp.cs
============================================================================
*/
