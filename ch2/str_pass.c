/**
 * @file str_pass.c
 * @brief 指针作为参数传递
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
# include<stdio.h>

void hello_cookie(char msg[]) {
    printf("cookie 消息内容 : %s\n", msg);
    // c 语言是值传递，传递给函数的变量是一个指向变量地址的指针,所以这里打印出来的长度是 8 指针的长度
    printf("cookie 消息长度 : %lu\n", sizeof(msg));
}

/**
 * @brief 数组变量不能指向其他地方
 * 计算机会为数组分配空间
 * 但是不会为数组变量分配空间
 * 编译器仅在出现它的地方将它替换为数组的起始地址
 * 但是由于计算机没有为数组变量分配空间
 * 数组变量就不会指向其它地方
 */
void arr_var() {
    int drinks[] = {1, 2, 3};
    printf("数组变量的值: %p\n", drinks);
    printf("数组变量的内存地址: %p\n", &drinks);

    /**
     * drinks[0] 和 *drinks 是等价的
     * 因为 drinks 的值为数组变量
     * 是数组起始元素的内存地址
     * *drinks 是内存地址的解引用，对应内存地址存储的元素
     * drinks[i] = *(drinks + i)
     */
    printf("drinks[0] 的值 %i \n", drinks[0]);
    printf("*drinks 的值 %i \n", *drinks);
    printf("drinks[%i] 的值 %i , *(drinks + %i) 的值: %i\n",
           1, drinks[1], 1, *(drinks + 1));
}

void skip(char *msg) {
    puts(msg + 6);
}

void pointer_arr() {
    /**
     * @brief 不同类型指针变量进行算数运算的结果不同
     * int 指针加 1 指针会指向下加上4的寄存器的地址
     * 因为 int 类型占用 4 字节
     */
    int ints[] = {1, 2, 3};
    printf("ints 中元素的地址 ints: %p ints + 1: %p ints + 2: %p",
           ints, ints + 1, ints + 2);
    long longs[] = {1, 2, 3};
    printf("ints 中元素的地址 longs: %p longs + 1: %p longs + 2: %p",
           longs, longs + 1, longs + 2);
}

int str_pass_main() {
    char msg[] = "hello cookies";
    /**
     * sizeof() 方法返回某条数据或者某种数据类型占据内存空间的大小
     */
    printf("char 长度 %lu\n", sizeof(char));
    printf("msg 长度 %lu\n", sizeof(msg));
    hello_cookie(msg);

    /**
     * 计算机会为字符串中的每一个字符和结束字符 \0 在栈上分配空间
     * 并把首字符的地址和 msg 变量关联起来
     * 所以这里打印出来的 msg 变量的值和首字符的内存地址是相同的
     * 字符串中后续的字符是连续的内存地址
     * 代码中如果出现这个变量
     * 计算机就会把这个变量替换成字符串首字符的地址
     * 所以将这个变量传递给函数实际上是传递了一个指针
     */
    printf("msg 变量指针的值 %p\n", msg);
    printf("msg[0] 的存储地址 %p\n", &msg[0]);
    printf("msg[1] 的存储地址 %p\n", &msg[1]);

    for (int i = 0; i < 13; i++) {
        printf("msg[%i] 的值：%c, 内存地址：%p\n", i, msg[i], &msg[i]);
    }

    arr_var();

    char *msgs = "don't call me!";
    skip(msgs);

    pointer_arr();
    return 0;
}