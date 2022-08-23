/*
 * @author 刘昂林 
 * @date 2022/8/23
 * @brief 比较器函数
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scores[] = {11, 9 , 2, 31, -10, 30};

/*
 * 矩形
 */
typedef struct rectangle {
    unsigned int width; // 宽
    unsigned int height; // 高
} rectangle;

/**
 * 比较器函数
 * void * 指针可以指向任何数据类型
 * 但是在使用之前必须转换为具体的类型
 * @param score_a 需要比较的任意类型参数 a
 * @param score_b 需要比较的任意类型参数 b
 * @return 比较结果 a - b
 */
int compare(const void* score_a, const void* score_b) {
    /*
     * *(int *)score_a
     * (int *)score_a 将 void 指针转换成 int 类型指针
     * *(int *)score_a 得到保存在指针地址的具体的值
     */
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    /*
     * 如果 a > b 就返回正数
     * a < b 返回负数
     * a = b 返回 0
     */
    return a - b;
}

int compare_desc(const void* score_a, const void* score_b) {
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return b - a;
}

void display(int array[]) {
    int *first = array;
    for (int i = 0; i< 6; i ++)
        printf("%d ", *(first + i));
    puts("");
}

/**
 * 比较两个矩形面积的大小
 * @param a 矩形结构指针
 * @param b 矩形结构指针
 * @return 比较结果
 */
int compare_rectangle_area(const void* a, const void* b) {
    // 将指针转换成对应的类型指针
    rectangle* rec_a = (rectangle*)a;
    rectangle* rec_b = (rectangle*)b;
    // 计算矩形结构面积
    int area_a = (int)(rec_a->height * rec_a->width);
    int area_b = (int)(rec_b->height * rec_b->width);
    return area_a - area_b;
}

/**
 * 比较姓名的顺序，区分大小写
 * @param name_a
 * @param name_b
 * @return
 */
int compare_names(const void* name_a, const void* name_b) {
    // 字符串是字符指针，所以得到的是指针的指针
    char** a = (char**)name_a;
    char** b = (char**)name_b;
    // *a 获取字符串
    return strcmp(*a, *b);
}

int main() {
    /*
     * qsort(void *__base, size_t __nel, size_t __width,
     * int (* _Nonnull __compar)(const void *, const void *)
     * qsort 是排序函数
     * void *__base 是一个数组指针
     * size_t __nel 是数组的长度
     * size_t __width 是是数组中每个元素的长度
     * int (* _Nonnull __compar)(const void *, const void *) 是比较器函数
     * 比较器返回一个整型数值，比较第一个参数值和第二个参数值
     * 如果第一个参数值大于第二个参数值，则返回正数
     * 如果相等，则返回 0
     * 如果第一个参数小于第二个参数，则返回负数
     */
    qsort(scores, 6, sizeof(int), compare);
    display(scores);

    qsort(scores, 6, sizeof(int), compare_desc);
    display(scores);

    rectangle rec1 = {3, 3};
    rectangle rec2 = {2, 5};
    rectangle rec3 = {1, 2};

    rectangle recs[] = {rec1, rec2, rec3};

    qsort(recs, 3, sizeof(rectangle), compare_rectangle_area);

    for (int i = 0; i < 3; i++) {
        printf("%d ", (recs + i)->width * (recs + i)->height);
    }
    puts("");

    char* strings[] = {"carl", "kevin", "adam", "Dude", "Adel"};

    qsort(strings, 5, sizeof(char*), compare_names);

    for (int i = 0; i < 5; i++) {
        printf("%s ", *(strings + i));
    }
}