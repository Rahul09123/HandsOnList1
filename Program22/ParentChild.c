/*
============================================================================
Name : ParentChild.c
Author : Rahul Raman
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 4th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

void main(){
    int fd;
    fd = open("common.txt",O_CREAT|O_RDWR,0644); //create and open the file
    if(!fork()){ //child
        write(fd,"Child is Writing",17); //child write the file

    }else{ //parent
        write(fd,"Parent is Writing",18); //parent write the file
        wait(NULL); //wait to finish one of the child execution
        
    }

}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program22$ cc ParentChild.c 
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program22$ ./a.out
============================================================================
*/
