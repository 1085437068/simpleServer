/*************************************************************************
	> File Name: tcp_server.c
	> Author: 
	> Mail: 
	> Created Time: 2021年04月28日 星期三 08时55分35秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>


int main(int argc, char* argv[]){
    int listenFd = socket(AF_INET, SOCK_STREAM, 0);  //创建套接字

    struct sockaddr_in serverAddr, clientAddr; //保存网络地址信息的结构体
    memset(&serverAddr, 0, sizeof(serverAddr));  //赋初始值
    serverAddr.sin_family = AF_INET;  //协议族/地址族
    serverAddr.sin_port = htons(atoi("8080"));  //保存端口号:转换为大端序
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //ip地址

    //绑定本地地址和端口
    int ret = bind(listenFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    ret = listen(listenFd, 100);

    int clientFd;
    int cliLen = sizeof(clientAddr);
    while(1){
        clientFd = accept(listenFd, (struct sockaddr*)&clientAddr, &cliLen);
        char buff[1024] = {0};
        ret = read(clientFd, buff, 1024); //接受数据,阻塞
        printf("recv a mag:%s\n", buff);
        close(clientFd);
    }

    close(listenFd);
    return 0;
}
