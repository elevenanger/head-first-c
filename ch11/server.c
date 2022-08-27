/*
 * @author 刘昂林 
 * @date 2022/8/26
 * @brief  
 */
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *advice[] = {
            "Take smaller bites\r\n",
            "Go for the tight jeans. No they do NOT make you look fat.\r\n",
            "One word: inappropriate\r\n",
            "Just for today, be honest. Tell your boss what you *really* think\r\n",
            "You might want to rethink that haircut\r\n"
    };

    // 创建套接字
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t) htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    // 将套接字绑定到 30000 端口
    if (bind(listener_d, (struct sockaddr*) &name, sizeof(name)))
        fprintf(stderr, "无法绑定端口");
    // 把监听队列设置为 10
    listen(listener_d, 10);

    puts("Waiting for connection");

    // 循环接受队列，然后开始这段逻辑
    while (1) {
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        int connect_d =
            // 接收来自客户端的连接
            accept(listener_d,
               (struct sockaddr*) &client_addr,
               &address_size);

        char *msg = advice[rand() % 5];

        // 开始和客户端通信
        send(connect_d, msg, strlen(msg), 0);
        close(connect_d);
    }
    return 0;
}