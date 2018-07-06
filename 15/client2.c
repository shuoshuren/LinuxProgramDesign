#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char ch = 'A';
    //创建套接字
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    //命名套接字
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = 9734;
    len = sizeof(address);
    //连接到服务器的套接字
    result = connect(sockfd,(struct sockaddr *)&address,len);

    if(result == -1){
        perror("oops: client2");
        exit(1);
    }

    //通过sockfd进行读写操作
    write(sockfd,&ch,1);
    read(sockfd,&ch,1);
    printf("char from server=%c\n",ch);
    close(sockfd);
    exit(0);

}
