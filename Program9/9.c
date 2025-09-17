/*
============================================================================
Name : 9.c
Author : Rahul Raman
Description : 9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change

Date: 31st Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(int arg,char* argv[]){
	const char *filename = argv[1];

	struct stat file_info; // it gives the whole info about the file

	stat(filename,&file_info);
	printf("FileName:%s",filename);
	printf("Inode:%ld\n",(long)file_info.st_ino);
	printf(" Hard Links: %ld\n", (long)file_info.st_nlink);
	printf("Owner UID: %ld\n", (long)file_info.st_uid);
   	printf("Group GID: %ld\n", (long)file_info.st_gid);
	printf("Size (bytes): %lld\n", (long long)file_info.st_size);
	printf("I/O Block Size: %ld bytes\n", (long)file_info.st_blksize);
	printf("Blocks Allocated: %lld\n", (long long)file_info.st_blocks);
	printf("Last Access Time: %s", ctime(&file_info.st_atim.tv_sec));
	printf("Last Modification Time: %s", ctime(&file_info.st_mtim.tv_sec));
 	printf(" Last Status Time: %s", ctime(&file_info.st_ctim.tv_sec));
	return EXIT_SUCCESS;
}
/*
============================================================================
OUTPUT:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program9$ cc 9.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program9$ ./a.out
FileName:(null)Inode:3145728
 Hard Links: 32768
Owner UID: 0
Group GID: 4194304
Size (bytes): 32768
I/O Block Size: 140730969201464 bytes
Blocks Allocated: 103079215127
Last Access Time: Thu Jan  1 05:30:00 1970
Last Modification Time: Thu Jan  1 05:30:00 1970
 Last Status Time: Thu Jan  1 05:30:00 1970
 ============================================================================
*/