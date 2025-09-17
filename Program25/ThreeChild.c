/*
============================================================================
Name : ThreeChild.c
Author : Rahul Raman
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 4th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int i , j ,k; //these stores the p_id of the processes returned by fork
	if(!(i=fork())){ //child 1
		printf("Chlid 1 with Parent id : %d \n",getppid());
		sleep(3);
	}
	else{
		if(!(j = fork())){ //child 2
			printf("Chlid 1 with Parent id : %d \n",getppid());
			sleep(5);
		}
		else{
			if(!(k = fork())){ //child 3
				printf("Chlid 1 with Parent id : %d \n",getppid());
				sleep(10);
			}
			else{ //parent of all
				printf("Parent id : %d \n",getpid());
				waitpid(i,NULL,0);
			}
		}
	}
		
	return 0;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program25$ cc ThreeChild.c 
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program25$ ./a.out
Chlid 1 with Parent id : 6112 
Chlid 1 with Parent id : 6112 
Parent id : 6112 
Chlid 1 with Parent id : 6112
============================================================================
*/
