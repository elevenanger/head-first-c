/*
 * @author 刘昂林 
 * @date 2022/8/21
 * @brief  计算价格
 * 自定义头文件的名称用 "" 双引号括起来，而不是尖括号
 * 编译器看到尖括号会从标准库代码所在目录查找头文件
 * 看到双引号就会从本地目录查找文件
 * 本地头文件可以带目录名
 * 但是一般头文件和 .c 文件放在同一个目录
 */
#include <stdio.h>
#include "totaller.h"

float total = 0.0f;
short count = 0;
short tax_percent = 6;

int main() {
    float val;

    puts("不含税价格：");

    while (scanf("%f", &val) == 1) {
        printf("当前商品价格：%.2f\n", val);
        printf("迄今为止所有商品的含税的价格：%.2f\n", add_with_tax(val));
        puts("不含税价格：");
    }

    printf("\n 总含税价格：%.2f\n", total);
    printf("商品数量：%hi\n", count);

    return 0;
}

float add_with_tax(float f) {
    float tax_rate = 1 + tax_percent / 100.0;
    total = total + (f * tax_rate);
    count = count + 1;
    return total;
}
