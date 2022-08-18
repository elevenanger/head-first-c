/**
 * @file value_pass.c
 * @brief c 语言值传递
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
# include<stdio.h>

/**
 * @brief 
 * 
 * @param *lat 是一个指针变量，保存的是一个地址，这个地址中保存的是一个 int 类型变量
 * @param *lon 
 */
void go_south_east(int *lat, int *lon)
{
    /**
     * * 运算符和 & 运算符相反
     * * 运算符接收一个地址告诉你这个地址中保存的是什么数据
     * * 运算符可以描述成对于运算符的解引用
     * 通过解引用取出指针对应的数值
     * 然后对数值进行修改
     */
    *lat = *lat - 1;
    *lon = *lon + 1;
}

int main() 
{
    int latitude = 32;
    int longtitude = -64;
    /**
     * @brief c 语言是值传递
     * &latitude 传递 latitude 变量的内存地址
     */
    go_south_east(&latitude, &longtitude);
    
    printf("精度 %i 纬度 %i", latitude, longtitude);
}