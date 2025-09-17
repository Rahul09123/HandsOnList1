/*
============================================================================
Name : 16b.c
Author : Rahul Raman
Description : Write a program to perform mandatory locking.
	a. Implement read lock
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
    //initialization of the lock
	struct flock lock;
	int fd;
	fd = open("db.txt",O_RDONLY);
	lock.l_type = F_RDLCK; //read lock
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering into critical section\n");
    //setting the lock
	fcntl(fd,F_SETLKW,&lock); //set lock and wait
	printf("Entering into critical section\n");
	printf("In the critical secaion\n");
	printf("Enter into the unlock..\n");
	getchar();
	printf("Unlocked\n");
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("finish\n");
    close(fd);
}
/*
============================================================================
Output:
Terminal 1
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program16$ ./a.out
Before entering into critical section
Entering into critical section
In the critical secaion
Enter into the unlock..
 
Terminal 2:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program16$ ./a.out
Before entering into critical section
Entering into critical section
In the critical secaion
Enter into the unlock..
============================================================================
*/