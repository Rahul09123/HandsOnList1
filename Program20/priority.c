/*
============================================================================
Name : priority.c
Author : Rahul Raman
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 4th Sep, 2025.
============================================================================
*/


#include<stdio.h>

int main(){
    while(1){

    }
    return 0;
}

/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program20$ cc priority.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program20$ ./a.out &
[2] 15121
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program20$ sudo renice -n -10 15121
15121 (process ID) old priority 0, new priority -10
============================================================================
*/