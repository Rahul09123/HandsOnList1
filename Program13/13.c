/*
============================================================================
Name : 13.c
Author : Rahul Raman
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).

Date: 1st Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>

int main() {
    fd_set readfds;
    struct timeval tv;
    int retval;

    // Watch stdin (fd 0) to see when it has input
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // Set timeout = 10 seconds
    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for input on STDIN (10 seconds timeout)...\n");
    fflush(stdout);

    // select(nfds, &readfds, NULL, NULL, &tv)
    retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select()");
        exit(EXIT_FAILURE);
        
    } else if (retval == 0) {
        printf("No data within 10 seconds.\n");

    } else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            printf("Data is available on STDIN! Reading now...\n");

            char buf[1024];
            ssize_t n = read(STDIN_FILENO, buf, sizeof(buf)-1);
            if (n > 0) {
                buf[n] = '\0';
                printf("You entered: %s\n", buf);
            }
        }
    }

    return 0;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program13$ ./a.out
Waiting for input on STDIN (10 seconds timeout)...
hello
Data is available on STDIN! Reading now...
You entered: hello

asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program13$ ./a.out
Waiting for input on STDIN (10 seconds timeout)...
No data within 10 seconds.
============================================================================
*/