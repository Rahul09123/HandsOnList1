/*
============================================================================
Name : 5.c
Author : Rahul Raman
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 31st Aug, 2025.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>    
#include <unistd.h>   
#include <stdlib.h>   

int main() {

    int fd[5];
    char filename[20];
    // Create 5 files and store their FDs
    for (int i = 0; i < 5; i++) {
        snprintf(filename, sizeof(filename), "file%d.txt", i+1);
        fd[i] = open(filename, O_CREAT | O_RDWR, 0644);
        if (fd[i] == -1) {
            perror("open failed\n");
            exit(1);
        }

        printf("Created %s with file descriptor : %d\n", filename, fd[i]);
    }

    printf("Process PID : %d\n", getpid());
   // Infinite loop so we can inspect /proc/pid/fd
    while (1) {
        sleep(5);
    }

    return 0;
}
/*
============================================================================
Output:

asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program5$ cc CreateFile.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program5$ ./a.out
Created file1.txt with file descriptor: 3
Created file2.txt with file descriptor: 4
Created file3.txt with file descriptor: 5
Created file4.txt with file descriptor: 6
Created file5.txt with file descriptor: 7
Process PID: 6239

asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program5$ ls -l /proc/6239/fd
total 0
lrwx------ 1 asus asus 64 Aug 31 22:28 0 -> /dev/pts/0
lrwx------ 1 asus asus 64 Aug 31 22:28 1 -> /dev/pts/0
lr-x------ 1 asus asus 64 Aug 31 22:28 103 -> /usr/share/code/v8_context_snapshot.bin
lrwx------ 1 asus asus 64 Aug 31 22:28 2 -> /dev/pts/0
lrwx------ 1 asus asus 64 Aug 31 22:28 3 -> /home/asus/Desktop/Linux/Program5/file1.txt
lrwx------ 1 asus asus 64 Aug 31 22:28 4 -> /home/asus/Desktop/Linux/Program5/file2.txt
l-wx------ 1 asus asus 64 Aug 31 22:28 41 -> /home/asus/.config/Code/logs/20250831T220911/ptyhost.log
lrwx------ 1 asus asus 64 Aug 31 22:28 5 -> /home/asus/Desktop/Linux/Program5/file3.txt
lrwx------ 1 asus asus 64 Aug 31 22:28 6 -> /home/asus/Desktop/Linux/Program5/file4.txt
lrwx------ 1 asus asus 64 Aug 31 22:28 7 -> /home/asus/Desktop/Linux/Program5/file5.txt
============================================================================
*/

