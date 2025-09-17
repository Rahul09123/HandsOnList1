/*
============================================================================
Name : zombie.c
Author : Rahul Raman
Description : Write a program to create an zombie process.
Date: 4th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

    if(!fork()){ //child
        sleep(1);
        printf("Child Process id: %d\n",getpid());
        printf("Child exiting...\n");
        exit(0);
    }else{//parent
        sleep(10);
        printf("Parent Process id: %d so it's a zombie \n",getpid());
    }

    return 0;
}

/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program23$ gcc zombie.c -o ./zombie.out
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program23$ ./zombie.out
Child Process id: 24212
Child exiting...
Parent Process id: 24211 so it's a zombie 
============================================================================
*/