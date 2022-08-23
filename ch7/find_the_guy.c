/*
 * @author 刘昂林 
 * @date 2022/8/23
 * @brief 从数组中查找指定的数据
 */
#include <stdio.h>
#include <string.h>

int NUM_ADS = 7;

char *ADS[] = {
    "William: SBM GSOH likes sports, TV, dining",
    "Matt: SWM NS likes art, movies, theater",
    "Luis: SLM ND likes books, theater, art",
    "Mike: DWM DS likes trucks, sports and bieber",
    "Peter: SAM likes chess, working out and art",
    "Josh: SJM likes sports, movies and theater",
    "Jed: DBM likes theater, books and dining"
};

int sports_no_bieber(const char *string) {
    return strstr(string, "sports") &&
            !strstr(string, "bieber");
}

int sports_or_workout(const char *string) {
    return strstr(string, "sports") ||
            strstr(string, "work");
}

int ns_theater(const char *string) {
    return !strstr(string, "smoking") &&
            strstr(string, "theater");
}

int arts_theater_or_dining(const char *string) {
    return strstr(string, "art") ||
            strstr(string, "theater") ||
            strstr(string, "dining");
}


/**
 * 将函数作为参数
 * 在 find 函数中使用传入的函数进行逻辑处理
 * 在 c 语言中，函数也是指针变量
 * 例如：创建了一个 ns_theater(const char *string) 的函数
 * 也会创建了一个叫 ns_theater 的指针变量
 * 变量中保存了函数的地址
 * 只要把函数指针类型的参数传给 find() 方法
 * 就能调用指向它的函数
 * int (*match)(const char *) 是一个函数指针类型参数
 * match 为指针变量,用于保存函数的地址
 * int 为函数的返回类型
 * const char * 是函数的参数类型
 * 有了函数指针，就能把函数传递给函数
 * @param match 函数指针类型参数
 */
void find(int (*match)(const char *)) {
    int i;
    puts("查询结果：");
    puts("--------------");
    for (i = 0; i < NUM_ADS; i++) {
        /*
         * 也可以写成 (*match)(ADS[i])
         * 但是不这么写编译器也能识别
         * 一般不用这种写法
         */
        if (match(ADS[i])) {
            printf("%s\n", ADS[i]);
        }
    }
    puts("--------------");
}

int main() {
    /*
     * &func 表示 func 函数的地址
     * 不写 & 编译器也可以识别这个函数
     * 一般省略 &
     */
    find(&sports_no_bieber);
    find(sports_or_workout);
    find(ns_theater);
    find(arts_theater_or_dining);

    return 0;
}