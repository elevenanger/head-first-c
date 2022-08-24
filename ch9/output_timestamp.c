/*
 * @date 2022/8/24
 * @brief 系统调用输出时间戳
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now() {
    time_t t;
    time(&t);
    return asctime(localtime(&t));
}

int main() {
    char comment[80];
    char cmd[120];

    scanf(comment, 80, stdin);

    sprintf(cmd, "echo '%s %s'", comment, now());

    // system(cmd) 进行系统调用执行 cmd 命令
    system(cmd);

    return 0;
}