/**
 * 从多个文件中读取数据
 * 再讲数据写入多个文件中
 */
#include <stdio.h>
#include <string.h>

const char data_path[] = "/Users/liuanglin/Projects/head-first-c/data/";

/**
 * main() 函数的第二种形式
 * 两个参数
 * c 语言没有内置字符串，字符串数组其实是一个字符指针数组
 * argc 用来记录 *argv[] 数组中元素的个数
 * *argv[] 接收字符指针数组
 * ../ch3/multi_in_and_out.c -o ../exec/multi
 * ./multi a contains_a.csv b contains_b.csv others.csv
 * 命令行中,第一个参数是程序名 ./multi
 * 程序接收的第一个参数实际是 argv[1] -> a
 */
int main(int argc, char *argv[]) {

    /**
     * argc 记录字符指针数量
     * 一共 6 个参数
     */
    if (argc != 6) {
        puts("需要 5 个参数");
        return 1;
    }

    char line[80];

    char in_file[80];
    char out_file_a[80];
    char out_file_b[80];
    char out_file_c[80];

    strcpy(in_file, data_path);
    strcpy(out_file_a, data_path);
    strcpy(out_file_b, data_path);
    strcpy(out_file_c, data_path);

    strcat(in_file, "in.csv");
    strcat(out_file_a, argv[2]);
    strcat(out_file_b, argv[4]);
    strcat(out_file_c, argv[5]);

    /**
     * FILE *in 将创建一条数据流，从文件中读取数据
     * fopen(path, "r"); path 是文件路径， "r" 表示只读模式
     * 如果文件不存在 fopen() 会返回 1
     * fopen 一共有三种模式 r 读模式 w 写模式 a 追加模式
     * 创建数据流之后
     */
    FILE *in;
    if (!(in = fopen(in_file, "r"))) {
        fprintf(stderr, "无法打开文件 : %s\n", in_file);
        return 1;
    }

    FILE *out_a = fopen(out_file_a, "w");
    FILE *out_b = fopen(out_file_b, "w");
    FILE *out_c = fopen(out_file_c, "w");

    /*
     * 使用 fscanf() 从文件数据流中读取数据
     * 使用 fprintf() 往文件数据流中输出数据
     */
    while (fscanf(in, "%79[^\n]\n", line) == 1) {
        printf("读取到的数据 %s\n", line);
        if (strstr(line, argv[1]))
            fprintf(out_a, "%s\n", line);
        else if (strstr(line, argv[3]))
            fprintf(out_b, "%s\n", line);
        else
            fprintf(out_c, "%s\n", line);
    }

    // 当数据流使用完之后，使用 fclose() 关闭数据流
    fclose(in);
    fclose(out_a);
    fclose(out_b);
    fclose(out_c);

    return 0;
}