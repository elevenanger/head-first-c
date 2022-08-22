/*
 * @author 刘昂林 
 * @date 2022/8/22
 * @brief 水族馆调查问卷
 */
#include <stdio.h>

/*
 * 使用位字段指定一个字段有多少位(bit)
 * 这样可以节省存储空间
 */
typedef struct {
    /*
     * 字段都必须使用 unsigned 关键字
     * 表示是或否使用 1 位就够了
     */
    unsigned int first_visit:1;
    unsigned int come_again:1;
    // 一周有 7 天，所以需要 3 位
    unsigned int days_of_week:3;
} survey;

void display(survey s) {
    printf("come again : %s\n"
           "first visit : %s\n"
           "days of week : %i\n",
            s.come_again ? "Yes" : "No",
            s.first_visit ? "Yes": "No",
            s.days_of_week);
}

int main() {

    survey s1 = {1, 1, 5};
    survey s2 = {0, 0, 3};

    display(s1);
    display(s2);

}