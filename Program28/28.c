/*
============================================================================
Name : 28.c
Author : Rahul Raman
Description : Write a program to get maximum and minimum real time priority.
Date: 5th Sep 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(){
	
	int max_Priority,min_Priority;
	if((max_Priority = sched_get_priority_max(SCHED_RR)) == -1){
		perror("Error while getting Max Priority \n");
		return 0; //exit the program
	}
	
	printf("Max Priority: %d\n",max_Priority); //printts max priority

	if((min_Priority = sched_get_priority_min(SCHED_RR)) == -1){
		perror("Error while getting Min Priority \n");
		return 0; //exit program
	}
	printf("Min Priority: %d\n",min_Priority); //prints min priority
	return 0;


}

/*
============================================================================
OUTPUT
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program28$ cc 28.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program28$ ./a.out
Max Priority: 99
Min Priority: 1

============================================================================
*/