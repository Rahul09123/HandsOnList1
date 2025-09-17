/*
============================================================================
Name : orphan.c
Author : Rahul Raman
Description : Write a program to create an orphan process.
Date: 4th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){

    if(!fork()){ //child
        sleep(3);
        printf("Child Process id: %d\n",getpid());
        printf("Parent process id: %d\n",getppid());

    }else{//parent
        printf("Parent Process id: %d \n",getpid());
        printf("Parent exiting...\n");
        sleep(1);
    }

    return 0;
}
/*
============================================================================
Output:

asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program24$ cc orphan.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program24$ ./a.out
Parent Process id: 22962 
Parent exiting...
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program24$ Child Process id: 22963
Parent process id: 1910
============================================================================
*/

