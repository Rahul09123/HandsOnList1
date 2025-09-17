/*
============================================================================
Name : 3.c
Author : Rahul Raman
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 31st Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
	int fd;
	fd = creat("text3.txt",0644);
	printf("The file descriptor value: %d\n Sucessfully created\n",fd);
	close(fd);
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program3$ ./a.out
The file descriptor value: 3
 Sucessfully created
============================================================================
*/
