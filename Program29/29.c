/*
============================================================================
Name : 29.c
Author : Rahul Raman
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 5th Sep 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_FIFO:
            printf("Current policy: SCHED_FIFO \n");
            break;
        case SCHED_RR:
            printf("Current policy: SCHED_RR \n");
            break;
        case SCHED_OTHER:
            printf("Current policy: SCHED_OTHER \n");
            break;
        default:
            printf("Current policy: Unknown \n");
            break;
    }
}

int main() {
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(getpid());

    print_policy(policy);

    printf("Changed scheduling policy to SCHED_FIFO \n");

    policy = sched_getscheduler(getpid());
    
    print_policy(policy);

    param.sched_priority = 10; 
    printf("Changed scheduling policy to SCHED_RR \n");

    policy = sched_getscheduler(getpid());

    print_policy(policy);


    return 0;
}


/*
============================================================================
OUTPUT:

asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program29$ cc 29.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program29$ ./a.out
Current policy: SCHED_OTHER
Changed scheduling policy to SCHED_FIFO
Current policy: SCHED_OTHER
Changed scheduling policy to SCHED_RR
Current policy: SCHED_OTHER

============================================================================
*/