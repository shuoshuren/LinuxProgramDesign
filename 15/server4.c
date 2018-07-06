#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <signal.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    int server_sockfd,client_sockfd;
    int server_len,client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    
    //为服务器创建一个未命名的套接字
    server_sockfd = socket(AF_INET,SOCK_STREAM,0);
    //命名套接字
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);
    bind(server_sockfd,(struct sockaddr *)&server_address,server_len);

    //创建一个连接队列，开始等待客户进行连接
    listen(server_sockfd,5);
    signal(SIGCHLD,SIG_IGN);

    while(1){
    
        char ch;
        printf("server waiting\n");
        //接受一个连接
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address,&client_len);
        if(fork() == 0){//在子进程中进行读写才操作

            //对client_sockfd套接字上的客户进行读写操作
            read(client_sockfd,&ch,1);
            printf("char from client:%c\n",ch);
            sleep(5);
            ch++;
            write(client_sockfd,&ch,1);
            close(client_sockfd);
            exit(0);
        }else{
            close(client_sockfd);
        }
    }
}