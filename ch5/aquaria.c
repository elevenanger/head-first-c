/*
 * @author 刘昂林 
 * @date 2022/8/21
 * @brief 水族馆
 */
#include <stdio.h>

/*
 * 使用 typedef 关键字为结构创建别名
 * 使用结构时就不再需要再声明 struct 关键字
 * 别名就是类型名 pref
 * preference 是结构名
 * 结构名可以省略，只定义类型名即可
 */
typedef struct preference {
    const char *food;
    float exercise_hours;
} pref; // 将 preference 别名设置为 pref

/*
 * 使用 struct 结构
 * 将不同类型的数据封装成一个新的数据类型
 * 结构字段在存储器中存储的顺序和字段定义的顺序相同
 */
struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;

    /*
     * 使用另外一个 struct 作为 struct 的属性
     * 这种方式称为嵌套
     * 直接使用别名即可
     */
    pref care;
};

void catalog(struct fish f) {
    printf("%s is a %s with %i teeth. He is %i years old.\n",
           f.name, f.species, f.teeth, f.age); // 按属性名访问 struct 中的元素

    printf("%s's favorite food : %s, do %.2f hours exercise everyday!\n",
           f.name, f.care.food, f.care.exercise_hours);
}

void label(struct fish f) {
    printf("Name : %s\nSpecies : %s\n%i years old, %i teeth\n",
           f.name, f.species, f.age, f.teeth);
}

/*
 * 如果需要更新 struct 的数据
 * 需要告诉函数变量在存储器中的位置
 * 不能把结构作为参数传递
 * 而是要传递结构的指针
 */
void grow_up(struct fish *f) {
    /*
     * 不能使用 *t.age
     * *t.age 表示 t.age 这个存储器单元中的内容
     * 但是 t.age 不是一个存储器单元
     * 使用 (*t).age 指向 f.age
     */
    (*f).age = (*f).age + 1;
    printf("Happy birthday to %s, you are %i years old now!\n",
           /*
            * (*f).age 这种表示方法不是很好读
            * 还有一种结构指针表示的方法，使得代码更易于阅读
            * f->name 表示由 f 指向结构中的 name 字段
            * f->name 等价于 (*f).name
            */
           f->name, f->age);
}

int main() {
    struct fish snappy = {"Snappy", "Piranha", 69, 4, {"meat", 3.5f}};

    catalog(snappy);
    label(snappy);

    /*
     * 把一个 struct 变量赋值给另一个变量
     * 计算机会创建一个全新的副本
     * 重新分配存储器空间
     * 将每个字段都复制给新的变量
     */
    struct fish snappy2 = snappy;
    snappy2.name = "snappy no 2";
    snappy2.age = 5;

    /*
     * 方法调用中传入 struct 为形参赋值
     * 调用该方法是
     * c 语言是创建了一个 snappy 的副本
     */
    label(snappy2);
    label(snappy);

    /*
     * c 语言所有的赋值都会复制数据
     * 如果需要复制数据的引用
     * 应该赋值指针
     * 赋值指针
     * snappy3 和 snappy 变量都指向同一个 fish 结构
     * 修改其中一个变量的数据
     * 另一个变量的值也会随之变化
     */
    struct fish *snappy3 = &snappy;
    snappy3->name = "snappy3";

    label(snappy);

    grow_up(&snappy);
    label(snappy);

    return 0;
}