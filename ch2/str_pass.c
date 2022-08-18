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

void hello_cookie(char msg[])
{
    printf("cookie 消息内容 : %s\n", msg);
    // c 语言是值传递，传递给函数的变量是一个指向变量地址的指针,所以这里打印出来的长度是 8 指针的长度
    printf("cookie 消息长度 : %lu\n", sizeof(msg));
}

int main()
{
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
    
    for (int i = 0; i < 13; i++)
    {
        printf("msg[%i] 的值：%c, 内存地址：%p\n", i, msg[i], &msg[i]);
    }
    
    return 0;
}