/*************************************************************************
	> File Name: tcp_client.c
	> Author: 
	> Mail: 
	> Created Time: 2021年04月28日 星期三 09时13分12秒
 ************************************************************************/

#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>

int main(int argc, char* argv[]){
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi("8080"));
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int ret = connect(fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    char buff[1024] = {0};
    ret = read(0, buff, 1024);
    ret = write(fd, buff, ret-1);

    close(fd);
    return 0;
}
