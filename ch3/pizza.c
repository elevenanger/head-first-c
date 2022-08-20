/*
 * @author 刘昂林
 * @date 2022/8/20
 * @brief 识别处理命令行工具参数
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *delivery = "";
    int thick = 0;
    int count = 0;
    char ch;

    /**
     * getopt() 读取命令行参数和选项
     * d:t 表示有 -d -t 两个选项
     * d 后面有: 表示 -d 选项需要一个参数
     * -d dongguan -t -- cheese potato meat
     * 为了避免歧义
     * 使用 -- 隔离选项和参数
     * getopt() 看到 -- 就会停止读取选项
     * 把后面的内容作为参数读取
     */
    while ((ch = getopt(argc, argv, "d:t")) != EOF) {
        /*
         * switch 处理每个选项的逻辑
         * optarg 读取该选项的参数
         */
        switch (ch) {
            case 'd':
                delivery = optarg;
                break;
            case 't':
                thick = 1;
                break;
            default:
                fprintf(stderr, "未知操作 : %s\n", optarg);
                return 1;
        }
    }

    /*
     * optind 保存了从命令行中读取了多少选项
     * argc argv 跳过已经读取的选项
     * 经过这个处理之后 argv[0] 指向的是选项之后的第一个命令行参数
     */
    argc -= optind;
    argv += optind;

    if (thick)
        puts("厚壳");
    if (delivery[0])
        printf("配送至：%s\n", delivery);

    /*
     * 遍历剩余的参数
     * 执行相应逻辑
     */
    puts("浇头：");
    for (count = 0; count < argc; count++)
        puts(argv[count]);

    return 0;

}