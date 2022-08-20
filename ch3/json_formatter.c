/**
 * gcc json_formatter.c -o json 编译可执行文件
 * ./json < data.csv > data1.csv
 * 重定向输入为 data_in.csv 文件
 * 重定向输出为 data_out.csv 文件
 * 这个工具从标准输入中读取数据
 * 将其转换为 JSON 格式数据
 * 输出到标准输出
 * 为了构建一个大的工具链
 * 我们会创建很多小工具
 * 每个小工具只做一件简单的事情
 */
# include "stdio.h"

int main() {
    // 变量要定义在当前代码块的最前面
    float latitude; // 纬度
    float longitude; // 精度
    char info[40]; // 其他信息
    int started = 0; // 初始状态为 0

    puts("data[");

    /*
     * scanf() 接收指针
     * 参数使用 & 修饰符修饰
     */
    while (fscanf(stdin,
                    "%f %f %79[^\n]",
                    &latitude, &longitude, info) == 3) {
        // 如果已经有一条数据则在数据后面拼接上 , 换行输出下一行的数据
        if (started)
            fprintf(stdout, ",\n");
        else
            // 循环执行一遍之后就可以把状态设置为 1
            started = 1;
        if (latitude < -90 || latitude > 90) {
            /*
             * fprintf() 会把输入发送到数据流
             * stderr 是标准错误流
             * 防止标准输出中包含错误信息
             * 将错误数据输出到标准错误流中
             */
            fprintf(stderr, "纬度数据异常 : %f", latitude);
            return 2;
        }
        if (longitude < -180 || longitude > 180) {
            fprintf(stderr, "经度数据异常 : %f", longitude);
            return 2;
        }
        /*
         * printf() 接收的是值 所以不需要使用 & 修饰
         * 将数据格式化为 json
         */
        fprintf(stdout ,
                "{latitude: %f, longitude: %f, info:'%s'}",
                latitude, longitude, info);
    }

    puts("\n]");

    return 0;
}