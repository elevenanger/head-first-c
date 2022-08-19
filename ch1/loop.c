# include <stdio.h>

/**
 * main() 函数中调用这些函数
 * 需要在 main() 函数之前先声明这些函数
 */
void while_loop(int count);

void do_while_loop(int count);

void for_loop(int count);

int loop_main() {
    int count = 10;
    while_loop(count);
    do_while_loop(count);
    for_loop(count);
    return 0;
}

void while_loop(int count) {
    while (count > 0) {
        printf("while 循环：%i\n", count);
        count--;
    }
}

/**
 * @brief do while 循环体定义的语句至少执行一次
 * 
 * @param count 计数
 */
void do_while_loop(int count) {
    do {
        printf("do while 循环：%i\n", count);
        count--;
    } while (count > 0);
}

void for_loop(int count) {
    for (int i = 0; i < count; count--) {
        if (count == 8) continue; // continue 跳出本次循环，调到循环条件处
        if (count == 5) break; // break 跳出整个循环
        printf("for 循环：%i\n", count);
    }
}