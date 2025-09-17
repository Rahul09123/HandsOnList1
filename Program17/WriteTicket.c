#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/file.h>

int main(){
    int fd;
    char buffer[100];
    fd = open("ticket.txt",O_CREAT|O_RDWR,0644);
    if(fd == -1){
        perror("open unsuccessful\n");
        exit(1);
    }
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("Updating the value\n");
    fcntl(fd,F_SETLKW,&lock);
    ssize_t n;
    n = read(fd,buffer,sizeof(buffer)-1);
    int value = 0;
    buffer[n] = '\0';//setting the last char as null
    if(n == 0){
        //write 1 in the file
        value = 1;
        
    }
    else{
        value = atoi(buffer); // char -> int
        value++;
    }
    printf("New Ticket No. %d\n",value);
    lseek(fd,0,SEEK_SET);//setting the ptr to start of file
    int len = snprintf(buffer,sizeof(buffer),"%d\n",value); //convert the int -> char
    write(fd,buffer,len); //write the value in the buffer
    ftruncate(fd,len); //remove extra bytes from the file
    lock.l_type= F_UNLCK;
    fcntl(fd,F_UNLCK,&lock);
    close(fd);
    return 0;
}