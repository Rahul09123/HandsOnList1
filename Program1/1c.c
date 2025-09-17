/*
============================================================================
Name : 1c.c
Author : Rahul Raman
Description : FIFO (mkfifo Library Function or mknod system call)
Date: 31st Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int main(void) {
    const char *fifo = "myfifo";
    if (mkfifo(fifo, 0666) == -1) { 
        if (errno != EEXIST) { perror("mkfifo"); return 1; }
    }

    pid_t pid = fork();
    if (pid == -1) { perror("fork"); return 1; }

    if (pid == 0) {
        // child: reader
        int fr = open(fifo, O_RDONLY);
        if (fr == -1) { perror("open fifo for read"); return 1; }
        char buf[256];
        ssize_t n = read(fr, buf, sizeof(buf)-1);
        if (n > 0) {
            buf[n] = '\0';
            printf("Child read: %s\n", buf);
        } else {
            printf("Child read nothing or error\n");
        }
        close(fr);
        return 0;
    
    } else {
        // parent: writer
        // small sleep to ensure child is ready (not strictly required)
        sleep(1);
        int fw = open(fifo, O_WRONLY);

        if (fw == -1) { perror("open fifo for write"); return 1; }
        const char *msg = "Message through FIFO\n";
        if (write(fw, msg, strlen(msg)) == -1) { perror("write fifo"); close(fw); return 1; }
        close(fw);
        wait(NULL);
        return 0;
    }
}

/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program1$ cc 1c.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program1$ ./a.out
Child read: Message through FIFO
============================================================================
*/