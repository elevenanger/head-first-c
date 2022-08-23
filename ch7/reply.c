#include <stdio.h>

enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

typedef struct response {
    char *name;
    enum response_type type;
} response;

void dump(const response r) {
    printf("Dear %s,\n", r.name);
    puts("Unfortunately your last date contacted us to");
    puts("say that they will not be seeing you again");
}

void second_chance(const response r) {
    printf("Dear %s\n", r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call ASAP.");
}

void marriage(response r) {
    printf("Dear %s\n", r.name);
    puts("Congratulations! Your last date has contacted");
    puts("us with a proposal of marriage.");
}

response responses[] = {
        {"Mike", DUMP},
        {"Luis", SECOND_CHANCE},
        {"Matt", SECOND_CHANCE},
        {"William", MARRIAGE}};

/**
 * 遍历 responses 数组中的元素
 * 使用 switch 语句分局元素的 type 属性
 * 调用不同的方法
 * 但是每个方法的签名其实是一样的
 * 如果未来增加新的方法
 * 需要创建新的 switch 分支
 * 调用指定的方法
 */
void reply() {
    int i;
    for (i = 0; i < 4; i++) {
        switch (responses[i].type) {
            case DUMP:
                dump(responses[i]);
                break;
            case SECOND_CHANCE:
                second_chance(responses[i]);
                break;
            default:
                marriage(responses[i]);
                break;
        }
    }
}

/*
 * 函数指针数组
 * 要在数组中保存函数
 * 就要在数组中保存函数的具体特征
 * 声明函数的返回值类型以及接收的参数类型
 * void (*replies[])(response)
 * 函数指针数组变量名为 replies
 * 数组中所有的函数返回类型都是 void
 * 声明数组中所有函数都接收一个 response 类型的形参
 * 函数名是函数指针
 * 函数指针数组中的元素是符合数组函数定义的函数名
 * enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};
 * 枚举中枚举类型的顺序与函数的顺序相同
 * c 语言按照枚举类型声明的顺序为每个枚举类型分配一个从 0 开始的数字
 * 所以可以通过枚举获取数组中的函数指针
 * replies[DUMP] 等价于 dump 函数
 */
void (*replies[])(response) =
        {dump, second_chance, marriage};

void reply_by_replies() {
    int i;
    for (i = 0; i < 4; i++) {
        /*
         * replies 根据 responses[] 数组中元素的 type 属性确定需要调用哪个函数
         * replies 数组中的函数的参数为 responses 数组中的 response 类型元素
         */
        replies[responses[i].type](responses[i]);
    }
}

int main() {
    reply();
    puts("----func----");
    reply_by_replies();
    return 0;
}