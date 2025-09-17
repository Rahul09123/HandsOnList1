/*
============================================================================
Name : CopyFile.c
Author : Rahul Raman
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 31st Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 1024

int main(int argc, char *argv[]) {
    int fd1, fd2;
    char buffer[SIZE];
    ssize_t n;

    if (argc != 3) {
        write(2, "Usage: ./mycp <source> <destination>\n", 38);
        exit(1);
    }

    // Open source file (read-only)
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        perror("open source failed\n");
        exit(1);
    }

    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1) {
        perror("open destination failed\n");
        close(fd1);
        exit(1);
    }

    // Copy loop
    while ((n = read(fd1, buffer, SIZE)) > 0) {
        if (write(fd2, buffer, n) != n) {
            perror("write");
            close(fd1);
            close(fd2);
            exit(1);
        }
    }

    close(fd1);
    close(fd2);

    return 0;
}

/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program7$ echo "This is text present in File1" > file1.txt
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program7$ ./copyFile.out file1.txt file2.txt
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program7$ cat file2.txt
This is text present in File1
============================================================================
*/
