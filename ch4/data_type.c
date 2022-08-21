/*
 * @author 刘昂林 
 * @date 2022/8/21
 * @brief 数据类型
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
 * 声明与定义分离
 * 声明是一个函数的签名 ：包括函数名、形参类型和返回值类型
 * 一旦声明了函数就可以先调用函数再定义函数
 * 如果代码中有很多函数
 * 但是又不相管函数在文件中出现的顺序
 * 就可以在代码开头声明函数
 * 也可以把这些函数放到代码外，放到一个头文件中
 * 通过 #include 来包含头文件中的代码
 */
void data_size();
void divide();
void bit_operation();
void max_min_value();

void data_size() {
    puts("data type length:");

    printf("char 类型字符字节数:%lu\n", sizeof(char));
    printf("short 类型字符字节数:%lu\n", sizeof(short));
    printf("int 类型字符字节数:%lu\n", sizeof(int));
    printf("long 类型字符字节数:%lu\n", sizeof(long));
    printf("float 类型字符字节数:%lu\n", sizeof(float));
    printf("double 类型字符字节数:%lu\n", sizeof(double));

    /*
     * 在字符面前加 long
     * 可以让字符位数变长
     */
    printf("long int 类型字符字节数:%lu\n", sizeof(long int));
    printf("long long 类型字符字节数:%lu\n", sizeof(long long));

    /*
     * unsigned 修饰的值只能是非负数
     */
    printf("unsigned char 类型字符字节数:%lu\n", sizeof(unsigned char));
    printf("unsigned int 类型字符字节数:%lu\n", sizeof(unsigned int ));

    puts("");
}

void divide() {
    puts("divide:");

    int x = 10;
    int y = 4;

    printf("x/y = %d\n", x / y);
    printf("x/y = %.2f\n", (float) x / (float) y);

    puts("");
}

void bit_operation() {
    puts("bit operation :");

    short x = 2; // 010
    short y = 3; // 011

    printf("x | y = %d\n", x | y);
    printf("x & y = %d\n", x & y);
    printf("x ^ y = %d\n", x ^ y); // 异或运算

    puts("");
}

void max_min_value() {
    puts("各字符类型最大最小值：");

    printf("int 类型字符最大值：%i\n", INT_MAX);
    printf("int 类型字符最小值：%i\n", INT_MIN);

    printf("long 类型最大值：%lo\n", LONG_MAX);
    printf("long 类型最小值：%lo\n", LONG_MIN);

    printf("long long类型最大值：%llo\n", LONG_LONG_MAX);
    printf("long long类型最小值：%llo\n", LONG_LONG_MIN);

    printf("float 最大值：%f\n", FLT_MAX);
    printf("float 最小值：%f\n", FLT_MIN);

}

int main() {
    data_size();
    divide();
    bit_operation();
    max_min_value();

    return 0;
}
