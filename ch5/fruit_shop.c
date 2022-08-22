/*
 * @author 刘昂林 
 * @date 2022/8/22
 * @brief 水果店
 */
#include <stdio.h>

/*
 * 计量单位枚举
 * COUNT 数量
 * POUNDS 磅数
 * PINTS 品脱
 * enum 枚举创建后
 * 计算机会为列表中的每一个符号分配一个数字
 * 枚举变量也只保存数字
 * 使用枚举值来确定 union 中保存的数值类型
 */
typedef enum {
    COUNT, POUNDS, PINTS
} unit_of_measure;

/*
 * 数量
 * 不同水果的数量单位不同
 */
typedef union {
    short count;
    float weight;
    float volume;
} quantity;

typedef struct {
    const char *name;
    quantity amount;
    unit_of_measure units;
} fruit_order;

void display(fruit_order order) {
    if (order.units == PINTS)
        printf("%.2f pints of %s\n", order.amount.volume, order.name);
    if (order.units == POUNDS)
        printf("%.2f pounds of %s\n", order.amount.weight, order.name);
    if (order.units == COUNT)
        printf("%i %s\n", order.amount.count, order.name);
}

int main() {

    fruit_order banana = {"banana", {.weight = 2.2f}, POUNDS};
    fruit_order apple_juice = {"apple juice", {.volume = 1}, PINTS};
    fruit_order watermelon = {"watermelon", {.count = 2}, COUNT};

    display(banana);
    display(apple_juice);
    display(watermelon);

    return 0;
}

