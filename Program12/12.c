/*
============================================================================
Name : 12.c
Author : Rahul Raman
Description : Write a program to find out the opening mode of a file. Use fcntl.

Date: 1st Sep, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
    int fd;
    fd = open("text12.txt",O_RDWR|O_CREAT,0644);
    int flag = fcntl(fd,F_GETFL); //stores the file status info
    switch (flag & O_ACCMODE) { //O_ACCMODE -> bit mask to find the access mode of the file 
        case O_RDONLY: 
            printf("The file is opened in Read-only mode.\n");
            break;
        case O_WRONLY:
            printf("The file is opened in Write-only mode.\n");
            break;
        case O_RDWR:
            printf("The file is opened in Read/Write mode.\n");
            break;
        default:
            printf("Unknown access mode.\n");
            break;
    }
    close(fd);
    return 0;
}


/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program12$ cc 12.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program12$ ./a.out
The file is opened in Read/Write mode.
============================================================================
*/

