/*
============================================================================
Name : 1a.c
Author : Rahul Raman
Description : Creating soft link 
Date: 31st Aug, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
    const char *target1 = "/home/asus/Desktop/Linux/Program1text1.txt";
    const char *linkPath1 = "/home/asus/Desktop/Linux/Program1/softLink2";
    int a = symlink(target1,linkPath1); //creating soft link
    if(a == -1){
        perror("soft link failed\n");
        exit(1);
    }
    printf("Sucessfully Softlink created\n");

    return 0;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program1$ cc 1.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program1$ ./a.out 
Sucessfully Softlink created
============================================================================
*/


