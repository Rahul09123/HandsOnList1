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
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("Reading the value..\n");
    fcntl(fd,F_SETLKW,&lock);
    ssize_t n;
    n = read(fd,buffer,sizeof(buffer));
    if(n < 0){
        perror("Read Failed\n");
        exit(1);
    }
    else if(n > 0){ //there is some bytes to read
        printf("Current Ticket No. %s",buffer);
    }
    lock.l_type= F_UNLCK;
    fcntl(fd,F_UNLCK,&lock);
    close(fd);
    return 0;
}