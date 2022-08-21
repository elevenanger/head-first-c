/*
 * @author 刘昂林 
 * @date 2022/8/21
 * @brief 破译保险箱
 */
#include <stdio.h>

// 存放的误判
typedef struct {
    const char *desc;
    float value;
} swag;

// 密码组合
typedef struct {
    swag *s;
    const char *sequence;
} combination;

// 保险箱
typedef struct {
    combination numbers;
    const char *make;
} safe;

int main() {
    swag gold = {"Gold", 50000.0f};
    combination numbers = {&gold, "0831"};
    safe s = {numbers, "rama250"};

    printf("保险箱中的物品：%s\n", s.numbers.s->desc);

    return 0;
}