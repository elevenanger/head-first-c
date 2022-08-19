# include <stdio.h>
# include <string.h>

void print_reverse(char *s) {
    /*
     * size_t 相当于整型
     * 用于保存字符串的长度
     */
    size_t len = strlen(s);

    char *t = s + len - 1;

    while (t >= s) {
        printf("%c", *t);
        // 计算地址-指针算数运算
        t = t - 1;
    }
}

int main() {
    char str[10];
    puts("请输入字符串：");
    fgets(str, sizeof(str), stdin);
    print_reverse(str);
    return 0;
}