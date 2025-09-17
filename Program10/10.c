/*
============================================================================
Name : 10.c
Author : Rahul Raman
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.

Date: 1st Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    char buffer1[] = "Software System !";
    char buffer2[] = "Hello from File 10";
    ssize_t bytes_written;
    off_t offset_result;
    const char *filename = "lseek.txt";

    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);

    printf("Successfully opened file '%s' with file descriptor %d.\n", filename, fd);
  
    bytes_written = write(fd, buffer1, 10);

    printf("Wrote %ld bytes: '%s'\n", bytes_written, "Hello World");

    offset_result = lseek(fd, 10, SEEK_CUR); //offset of 10 
    
    printf("a. lseek() returned: %lld. File pointer is now at offset %lld.\n", 
           (long long)offset_result, (long long)offset_result);
    bytes_written = write(fd, buffer2, strlen(buffer2));
    printf("Wrote %ld bytes: '%s'\n", bytes_written, "Hello from File 10!");
    close(fd);

    return EXIT_SUCCESS;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program10$ cc 10.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program10$ ./a.out
Successfully opened file 'lseek.txt' with file descriptor 3.
Wrote 10 bytes: 'Hello World'
a. lseek() returned: 20. File pointer is now at offset 20.
Wrote 18 bytes: 'Hello from File 10!'
============================================================================
*/
