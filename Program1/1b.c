/*
============================================================================
Name : 1b.c
Author : Rahul Raman
Description : Creating hard link 
Date: 31st Aug, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
    const char *target2 = "/home/asus/Desktop/Linux/Program1/text1.txt";
    const char *linkPath2 = "/home/asus/Desktop/Linux/Program1/hardLink2";
    int b =  link(target2,linkPath2); //creating hard link
    if(b == -1){
        perror("hard link failed\n");
        exit(1);
    }
    printf("Sucessfully HardLink created\n");

    return 0;
}

/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program1$ cc 1b.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/Linux/Program1$ ./a.out 
Sucessfully HardLink created
============================================================================
*/
