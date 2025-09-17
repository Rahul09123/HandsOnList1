/*
============================================================================
Name : execle.c
Author : Rahul Raman
Description : Write a program to execute ls -Rl by the following system calls
                e. execle
Date: 5th Sep 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    int pid;

    printf("--- Executing ls -Rl using execle() ---\n");
    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return 1;
    }
    if (pid == 0) { // Child process
        char *const envp[] = {"variable=demo", "othervariable=123", NULL};
        execle("/bin/ls", "ls", "-Rl", NULL, envp);
        perror("execle failed");
        exit(1);
    } else { // Parent process
        wait(NULL);
    }
    return 0;
}
/*
============================================================================
Output:
--- Executing ls -Rl using execle() ---
.:
total 36
-rwxrwxr-x 1 asus asus 16224 Sep  5 20:02 a.out
-rw-rw-r-- 1 asus asus  1555 Sep  5 19:59 execl.c
-rw-rw-r-- 1 asus asus   871 Sep  5 20:02 execle.c
-rw-rw-r-- 1 asus asus  1445 Sep  5 20:00 execlp.c
-rw-rw-r-- 1 asus asus  1489 Sep  5 19:59 execv.c
-rw-rw-r-- 1 asus asus  1491 Sep  5 19:59 execvp.c
============================================================================
*/