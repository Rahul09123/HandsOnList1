/*
============================================================================
Name : 19.c
Author : Rahul Raman
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 4th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

// Time Stamp Counter
static inline uint64_t rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    long int start, end;
    int pid;

    start = rdtsc(); //start time
    end = rdtsc(); //end time
    pid = getpid();

    long int cycles = end - start;

    // Estimate CPU frequency (assumed 2.5 GHz, adjust as needed)
    double cpu_ghz = 2.5;
    double time_ns = (cycles / cpu_ghz); // Convert cycles to nanoseconds

    printf("Time for getpid: %.2f ns\n", time_ns);
    printf("PID: %d\n", pid);

    return 0;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program19$ cc 19.c 
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program19$ ./a.out
Time for getpid: 33.60 ns
PID: 7201
============================================================================
*/