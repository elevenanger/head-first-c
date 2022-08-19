# include<stdio.h>

int scanf_main() {
    int age;
    char first_name[10];
    char last_name[10];

    puts("输入您的身份信息");
    /**
     * scanf() 是一个函数
     * 更新数组的内容
     * 它需要的是一个变量的地址而不是变量本身的值
     * 数组变量就是一个 char 指针
     * 而要更新 int 类型变量的值
     * 则需要将指针作为参数进行传递
     * 使用 scanf 如果没有指定数组的长度
     * 则用户可以输入任意长度的数据
     * 多余的数据会写到计算机还没有分配的内存空间中
     * 如果内存空间足够不会有什么问题
     * 但是如果内存空间不足以保存这些数据就会导致程序出错
     */
    scanf("%9s %9s %i",
          first_name, last_name, &age);
    printf("first name : %s , last name : %s , age : %i",
           first_name, last_name, age);
}