/*============================================================================
Name : WriteRecordLock2.c
Author : Rahul Raman
Description : Write a program to perform Record locking.
	a. Implement write lock
Date: 3rd Sep, 2025.
============================================================================
*/
#include<sys/file.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){

    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_start = 12; //setting the start of the record
    lock.l_len = 5; //length of record lock
    lock.l_whence = SEEK_SET;
    lock.l_pid = getpid();
    int fd;
    fd = open("Record.txt",O_CREAT|O_RDWR);
    if(fd < 0){
        perror("Failed to open file\n");
        exit(1);
    }
	printf("Before entering into critical section\n");
	fcntl(fd,F_SETLKW,&lock); //set lock and wait
	printf("Entering into critical section\n");
	printf("In the critical section lockint %ld bytes of data\n",lock.l_len);
	printf("Enter into the unlock..\n");
	getchar();
	printf("Unlocked\n");
	lock.l_type = F_UNLCK; //unlocked
	fcntl(fd,F_SETLK,&lock); 
	printf("finished\n");

    return 0;
}



