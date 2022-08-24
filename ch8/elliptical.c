/*
 * @author 刘昂林 
 * @date 2022/8/24
 * @brief 椭圆机
 * gcc -I ../head_files elliptical.c hfcal.c -o ../object_files/elliptical.o
 * gcc -I 从指定目录查找 head 文件
 */
#include <stdio.h>
#include "../head_files/hfcal.h"

const float ELLIPTICAL_COEFF = 0.78f;

int main() {
    display_calories(139.5f, 5, ELLIPTICAL_COEFF);
    return 0;
}