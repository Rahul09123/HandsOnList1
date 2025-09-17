/*
============================================================================
Name : execv.c
Author : Rahul Raman
Description : Write a program to execute ls -Rl by the following system calls
                e. execv
Date: 5th Sep 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    int pid;

    printf("---Executing ls -Rl using execv()---\n");
    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return 1;
    }
    if (pid == 0) { // Child process
        char *const argv[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", argv);
        perror("execv failed");
        exit(1);
    } else { // Parent process
        wait(NULL);
    }
    return 0;
}
/*
============================================================================
Output:

asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program30$ cc execv.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program30$ ./a.out
--- Executing ls -Rl using execv() ---
.:
total 36
-rwxrwxr-x 1 asus asus 16216 Sep  5 19:10 a.out
-rw-rw-r-- 1 asus asus  1113 Sep  5 19:04 execl.c
-rw-rw-r-- 1 asus asus   885 Sep  5 19:06 execle.c
-rw-rw-r-- 1 asus asus   820 Sep  5 19:06 execlp.c
-rw-rw-r-- 1 asus asus   873 Sep  5 19:10 execv.c
-rw-rw-r-- 1 asus asus  1546 Sep  5 19:09 execvp.c
============================================================================
*/
