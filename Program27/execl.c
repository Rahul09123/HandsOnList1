/*
============================================================================
Name : 29.c
Author : Rahul Raman
Description : Write a program to execute ls -Rl by the following system calls
                a. execl.c
Date: 5th Sep 2025
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    int pid;
    printf("---Executing ls -Rl using execl()---\n");
    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return 1;
    }
    if (pid == 0) { // Child process
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl failed");
        exit(1);
    } else { // Parent process
        wait(NULL);
    }
    return 0;
}
/*
============================================================================
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program30$ cc execl.c 
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program30$ ./a.out
--- Executing ls -Rl using execl() ---
.:
total 36
-rwxrwxr-x 1 asus asus 16168 Sep  5 19:14 a.out
-rw-rw-r-- 1 asus asus  1267 Sep  5 19:14 execl.c
-rw-rw-r-- 1 asus asus   885 Sep  5 19:06 execle.c
-rw-rw-r-- 1 asus asus  1447 Sep  5 19:13 execlp.c
-rw-rw-r-- 1 asus asus  1493 Sep  5 19:13 execv.c
-rw-rw-r-- 1 asus asus  1495 Sep  5 19:13 execvp.c
============================================================================
*/
