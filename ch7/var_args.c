/*
 * 可变参数
 * 处理可变参数的代码都在 stdarg.h 标准库中
 */
#include <stdio.h>
#include <stdarg.h>

// 酒名
enum drink {MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE};

/**
 * 根据酒类型返回某种酒的单价
 * @param d 酒类型
 * @return 单价
 */
double price(enum drink d) {
    switch (d) {
        case MUDSLIDE:
            puts("MUDSLIDE");
            return 6.79;
        case FUZZY_NAVEL:
            puts("FUZZY_NAVEL");
            return 5.31;
        case MONKEY_GLAND:
            puts("MONKEY_GLAND");
            return 4.82;
        case ZOMBIE:
            puts("ZOMBIE");
            return 5.89;
        default:
            return 0;
    }
}

/**
 * 打印一组 int
 * @param args 要打印的 int 参数的数量 这个是普通参数
 * @param ... 要打印的参数 这个是可变参数
 * 参数数量可变的函数被称为可变参数函数
 * C 标准库有一组宏可以实现可变参数函数
 * 宏是一种特殊类型的函数，可以修改源代码
 * 宏用来在编译前重写代码
 * 这里用到的几个宏函数是一些指令
 * 在编译前，预处理器会根据这些指令在程序中插入代码
 */
void print_ints(int args, ...) {
    // va_list 用来保存给传给函数的其它参数
    va_list ap;
    /*
     * va_start(ap, args) 表示可变参数从哪里开始
     * 从 args 参数开始后面都是可变参数
     */
    va_start(ap, args);
    /*
     * 遍历所有的可变参数
     * args 保存了可变参数的数量
     * 参数全部保存在 va_list 中
     * 可以用 va_arg 读取它们
     * va_arg(ap, int) 接收两个值
     * va_list 和要读取的参数类型
     */
    int i;
    for (i = 0; i < args; i++) {
        printf("参数 : %i\n", va_arg(ap, int));
    }
    // 读取完了所有参数调用 va_end() 函数告诉 C 你做完了
    va_end(ap);
}

/**
 * 根据可变的酒水清单，计算总价格
 * @param args 酒水的数量
 * @param ... 酒水
 * @return 酒水总价格
 */
double total_price(int args, ...) {
    double total_price = 0;
    va_list drinks;
    va_start(drinks, args); // 设置从哪里开始
    int i;
    for (i = 0; i < args; i++)
        total_price += price(va_arg(drinks, enum drink));
    va_end(drinks);
    return total_price;
}

int main() {
    print_ints(4, 2, 3, 6, 7);
    double total = total_price(4, ZOMBIE, MONKEY_GLAND, FUZZY_NAVEL, MUDSLIDE);
    printf("总价格 : %.2f\n", total);
}