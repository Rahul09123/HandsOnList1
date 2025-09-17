/*
============================================================================
Name : executableProgram.c
Author : Rahul Raman
Description : Write a program to execute an executable program.
                a. use some executable program
Date: 4th Sep, 2025.
============================================================================
*/
#include <stdlib.h>

int main() {
    system("./a.out"); // 'program' will be passed as argv[1] to a.out
    return 0;
}
