/*
 * @author 刘昂林 
 * @date 2022/8/22
 * @brief 调制玛格丽特
 * 组合使用 struct 和 union
 */
#include <stdio.h>
#include <float.h>

/*
 * 使用 union 来表示数据结构
 * 定义 union 时，计算机只为其中最大的字段分配空间
 */
typedef union {
    float lemon;
    int lime_pieces;
} lemon_lime;

typedef struct {
    float tequila;
    float cointreau;
    lemon_lime citrus;
} margarita;

void initial_lemon_lime() {
    /*
     * 使用了 c89 表示法初始化 union 实例
     * 如果 union 要保存第一个字段的值
     * 只要大括号把值括起来即可赋值给第一个字段
     */
    lemon_lime lime_c89 = {2.1f};
    printf("lemon_lime lemon : %.2f\n", lime_c89.lemon);

    /*
     * 指定初始化器
     * 按名设置 union 中字段的值
     */
    lemon_lime lime_designated = {.lemon = 2.2f};
    printf("lemon_lime lemon : %.2f\n", lime_designated.lemon);

    /*
     * 使用点表示法
     * 首先创建 union 变量
     * 然后设置字段的值
     * 无论使用那种方法设置 union 的值
     * 都只会保存一条数据
     * 即 union 多个字段中只有一个字段可以赋值
     * union 只是提供了一种创建支持不同数据类型的变量的方式
     */
    lemon_lime lime;
    lime.lemon = 2.3f;
    lime.lime_pieces = 2;
    printf("lemon_lime lemon : %.2f has %i pieces.\n",
           lime.lemon, lime.lime_pieces);
}

void make_margarita(margarita m) {

    if (m.citrus.lemon > FLT_EPSILON)
        printf("Margarita has compound %.2f ounces cointreau, "
               "%.2f ounces tequila and "
               "%.2f ounces lemon juice.\n",
               m.tequila, m.cointreau, m.citrus.lemon);
    else if (m.citrus.lime_pieces > 0)
        printf("Margarita has compound %.2f ounces cointreau, "
                "%.2f ounces tequila and "
                "%i pieces lemon.\n",
                m.tequila, m.cointreau, m.citrus.lime_pieces);
}

int main() {

    initial_lemon_lime();

    /*
     * struct 也可使用使用点表示法来设置字段的值
     * union 经常和 struct 一起使用
     * 可以在 union 中保存各种可能的值
     * 一旦保存以后
     * 编译器就无法知道它的类型
     */
    margarita m1 = {.cointreau = 1.6f,
                       .tequila = 2.3f,
                       .citrus.lime_pieces = 3};
    margarita m2 = {1.7f, 2.6f, {2.2f}};
    margarita m3 = {2.2f, 2.3f, .citrus.lime_pieces = 4};
    margarita m4 = {2.2f, 2.3f, {.lemon = 2.9f}};

    make_margarita(m1);
    make_margarita(m2);
    make_margarita(m3);
    make_margarita(m4);

    return 0;
}