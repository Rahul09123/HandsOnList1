/*
============================================================================
Name : 16a.c
Author : Rahul Raman
Description : Write a program to perform mandatory locking.
	a. Implement write lock
Date: 1st Sep, 2025.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
	struct flock lock;
	int fd;
	fd = open("db.txt",O_RDWR);
	lock.l_type = F_WRLCK; //write lock
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering into critical section\n");
	fcntl(fd,F_SETLKW,&lock); //set lock and wait
	printf("Entering into critical section\n");
	printf("In the critical section\n");
	printf("Enter into the unlock..\n");
	getchar(); //waiting for a character input
	printf("Unlocked\n");
	lock.l_type = F_UNLCK; //unlocked
	fcntl(fd,F_SETLK,&lock); 
	printf("finish\n");
}

/*
============================================================================
Output:
If one process into critical section then another process will wait outside
Terminal1:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program16$ cc 16a.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program16$ ./a.out
Before entering into critical section
Entering into critical section
In the critical section
Enter into the unlock..


Terminal2:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program16$ ./a.out
Before entering into critical section

============================================================================
*/