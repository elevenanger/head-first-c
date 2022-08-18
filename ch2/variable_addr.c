/**
 * @file variable_addr.c
 * @brief 变量的内存地址
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
# include <stdio.h>

/**
 * @brief 函数外声明的变量位于内存地址的全局量段
 * 每声明一个变量
 * 计算机都会在寄存器中为这个变量创建存储空间
 * 如果在函数中声明的变量
 * 保存在一个叫做栈的内存地址段中
 * 如果在函数外声明变量
 * 保存在存储器的全局量段中
 */
int out_func = 1;

int main()
{
    /**
     * @brief %p 用户格式化指针地址
     * &out_func 表示变量内存地址 16 进制的值
     * 变量的地址指向变量在存储器中的位置
     * 这个地址也称作指针，它指向了存储器中的变量
     */
    int in_func = 2;
    int in_func1 = out_func;
    printf("函数外变量内存地址：%p\n", &out_func);
    printf("函数内变量内存地址：%p\n", &in_func);
    printf("函数内变量内存地址：%p\n", &in_func1);
    return 0;
}