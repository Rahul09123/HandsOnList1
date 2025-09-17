/*
============================================================================
Name : execute.c
Author : Rahul Raman
Description : Write a program to execute an executable program.
                a. use some executable program
Date: 4th Sep, 2025.
============================================================================
*/
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("%s\n", argv[1]); // Prints input argument
    return 0;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program26$ gcc executableProgram.c -o ./ep.out
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program26$ gcc execute.c -o ./execute.out
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program26$ ./execute.out HelloFromExecutableProgram
HelloFromExecutableProgram
============================================================================
*/