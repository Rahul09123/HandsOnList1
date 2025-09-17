/*
============================================================================
Name : CopyFile.c
Author : Rahul Raman
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 31st Aug, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    char buffer[50];
    int n;
    n = read(0,buffer,sizeof(buffer));
    if(n == 2){
        perror("Failed\n");
        exit(1);
    }
    write(1,buffer,sizeof(buffer));


    return 0;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program7$ cc copyFile.c 
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program7$ ./a.out
ThisTextisFromCopyFile
ThisTextisFromCopyFile
============================================================================
*/
