/*
 * @author 刘昂林 
 * @date 2022/8/26
 * @brief  创建线程
 */
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void* does_not(void *a) {
    int i = 0;
    for (i = 0; i < 5; i++) {
        sleep(1);
        puts("Does not!");
    }
    return NULL;
}

void* does_too(void *a) {
    int i = 0;
    for (i = 0;  i < 5; i++) {
        sleep(1);
        puts("Does too");
    }
    return NULL;
}

void error(char *msg) {
    fprintf(stderr, "%s %s\n", msg, strerror(errno));
    exit(1);
}

int main() {
    /*
     * 保存了线程的信息
     */
    pthread_t t0;
    pthread_t t1;

    // 创建线程
    int p1 = pthread_create(&t0, NULL, does_not, NULL);
    int p2 = pthread_create(&t1, NULL, does_too, NULL);

    printf("p1 %i; p2 %i\n", p1, p2);

    if (p1 == -1)
        error("无法创建线程t0");

    if (p2 == -1)
        error("无法创建线程t1");

    // 函数返回返回的 void 指针将保存在这个位置
    void *result;

    // pthread_join 将等待线程结束
    if (pthread_join(t0, &result) == 0)
        error("无法回收线程！");
    if (pthread_join(t1, &result) == 0)
        error("无法回收线程！");


    return 0;
}