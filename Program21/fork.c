/*
============================================================================
Name : fork.c
Author : Rahul Raman
Description : Write a program, call fork and print the parent and child process id.
Date: 4th Sep, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>

int main(){
    if(!fork()){
        printf("Child Process id %d \n its Parent process %d\n",getpid(),getppid());
    }else{
        printf("Parent process id: %d\n",getpid());
    }
    return 0;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program21$ gcc fork.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program21$ ./a.out
Parent process id: 16004
Child Process id 16005 
 its Parent process 16004
============================================================================
*/