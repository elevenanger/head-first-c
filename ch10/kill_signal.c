/*
 * @author 刘昂林 
 * @date 2022/8/26
 * @brief  捕捉程序的中断信号
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/**
 * 接收信号，处理程序的终止操作
 * @param sig 信号
 */
void die(int sig) {
    puts("Process has been killed! \n");
    exit(1);
}

/**
 * 捕捉信号进行处理
 * @param sig 信号编号
 * @param handler 处理器指针
 * @return
 */
int catch_signal(int sig, void (*handler) (int)) {
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    /*
     * sigaction 函数接收三个参数
     * sig 表示希望处理的信号
     * action 新动作，想注册新的 sigaction 的地址
     * 旧动作 保存被替换的信号处理器
     * 如果不需要则设置为 NULL
     */
    return sigaction(sig, &action, NULL);
}

int main() {
    if (catch_signal(SIGINT, die) == -1) {
        fprintf(stderr, "Can't map handler");
        exit(2);
    }

    char name[30];
    printf(":Enter your name:");
    fgets(name, 30, stdin);
    printf("Hello %s \n", name);
    return 0;
}