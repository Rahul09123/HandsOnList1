/*
============================================================================
Name : 14.c
Author : Rahul Raman
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 3rd Sep 2025
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2){
        printf("Enter the name of the file as the argument\n");
        return 0;
    }
    
    int fd = open(argv[1], O_RDONLY);   
    struct stat statbuf;

    fstat(fd, &statbuf);

    if (S_ISREG(statbuf.st_mode))
        write(STDOUT_FILENO, "Regular File\n", 13);
    else if (S_ISDIR(statbuf.st_mode))
        write(STDOUT_FILENO, "Directory File\n", 15);
    else if (S_ISCHR(statbuf.st_mode))
        write(STDOUT_FILENO, "Character File\n", 15);
    else if (S_ISBLK(statbuf.st_mode))
        write(STDOUT_FILENO, "Block File\n", 11);
    else if (S_ISFIFO(statbuf.st_mode))
        write(STDOUT_FILENO, "FIFO File\n", 10);
    else if (S_ISLNK(statbuf.st_mode))
        write(STDOUT_FILENO, "Symbolic Link File\n", 19);
    else if (S_ISSOCK(statbuf.st_mode))
        write(STDOUT_FILENO, "Socket\n", 7);
    else
        write(STDOUT_FILENO, "Error\n", 6);
    return 0;
}



/*
============================================================================
OUTPUT

asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program14$ cc 14.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program14$ ./a.out sample.txt
Regular File

============================================================================
*/