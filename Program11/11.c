/*
============================================================================
Name : 11.c
Author : Rahul Raman
Description : 11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl

Date: 1st Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<stdlib.h>

int main(){
    int dup_1, dup_2 ,dup_3;
    int fd = open("test.txt",O_CREAT|O_WRONLY|O_APPEND,0644);

    //duplicate using dup
    dup_1 = dup(fd);
    if(dup_1 == -1){
        perror("Not opened successfully\n");
        exit(1);
    }
    //duplicate using dup2
    dup_2 = dup2(fd,5);
    if(dup_2 == -1){
        perror("dup_2 error\n");
        exit(1);
    }
    //duplicate using fcntl
    dup_3 = fcntl(fd,F_DUPFD,12);
    if(dup_3 == -1){
        perror("dup_3 error\n");
        exit(1);
    }
    write(dup_1,"From dup_1\n",11);
    write(dup_2,"From dup_2\n",11);
    write(dup_3,"From dup_3 using fcntl\n",24);

    printf("The fileDescriptor of dup1, dup2 and dup3 are %d, %d, %d\n",dup_1,dup_2,dup_3);
    
    close(fd);
    close(dup_1);
    close(dup_2);
    close(dup_3);

    return 0;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program11$ cc 11.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program11$ ./a.out
The fileDescriptor of dup1, dup2 and dup3 are 4, 5, 12
============================================================================
*/