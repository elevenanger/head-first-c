/**
 * @file fgets_input.c
 * @brief fgets() 方法接收 char 指针，但是必须给出最大长度
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
# include<stdio.h>

int fgets_main() {
    char food[5];
    puts("请输入需要的食物：\n");
    /**
     * fgets(pointer, size , input)
     * fgets 缓冲区已经把 \0 也算进去了
     * 所以不需要再 -1
     */
    fgets(food, sizeof(food), stdin);
    printf("输入的食物：%s\n", food);
}