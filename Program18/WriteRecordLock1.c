/*============================================================================
Name : WriteRecordLock1.c
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
    lock.l_start = 12; //start of record lock
    lock.l_len = 10; //length of record lock
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
	printf("In the critical section locking %ld bytes of data\n",lock.l_len);
	printf("Enter into the unlock..\n");
	getchar(); //waiting 
	printf("Unlocked\n");
	lock.l_type = F_UNLCK; //unlocked
	fcntl(fd,F_SETLK,&lock); 
	printf("finished\n");

    return 0;
}
/*
============================================================================
Output:
Terminal 1: 
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program18$ cc WriteRecordLock1.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program18$ ./a.out
Before entering into critical section
Entering into critical section
In the critical section locking 5 bytes of data
Enter into the unlock..


Terminal 2:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program18$ cc WriteRecordLock2.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program18$ ./a.out
Before entering into critical section

============================================================================
*/



