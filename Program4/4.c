/*
============================================================================
Name : 4.c
Author : Rahul Raman
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 31st Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(void){
	int fd1,fd2;
	fd1 = open("text4.txt",O_RDWR); //opened using read write mode
	fd2 = open("text4.txt",O_EXCL);
	if(fd1 == -1){
		perror("Failed fd1\n");
		exit(1);
	}
	if(fd2 == -1){
		perror("Failed fd2\n");
		exit(1);
	}
	printf("File Descriptor value using read/write %d\n",fd1);
	printf("File Descriptor value using o_excl %d\n",fd2);
	close(fd1);
	close(fd2);
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program4$ ./a.out
File Descriptor value using read/write 3
File Descriptor value using o_excl 4
============================================================================
*/