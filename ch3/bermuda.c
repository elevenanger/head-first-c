/**
 * 从标准输入中读取坐标数据
 * 只处理坐标落在百慕大坐标范围的数据
 * proc1 | proc2
 * 符号 | 表示管道
 * 不同操作系统实现管道的方式不同
 * 有的是用文件，有的是用存储器
 * 但是本质上都是从一端接收数据
 * 然后在另一端发送数据
 * 使用管道连接一个进程的标准输出和另一个进程的标准输入
 * (./bermuda|./json) < data_in.csv > data_out.csv
 * 将 bermuda 和 json 组成一个工具链
 * < 将文件内容发送到工具链中的第一个进程的标准输入
 * > 将捕获工具链最后一个进程的标准输出
 * 从 data_in.csv 中读取数据
 * 将数据输出至 data_out.csv 文件中
 */
# include <stdio.h>

int main() {
    float latitude;
    float longitude;
    char info[80];

    while (scanf("%f %f %79[^\n]",
                 &latitude, &longitude, info) == 3)
        // 过滤经度和维度在指定区间的数据
        if (latitude > 26 && latitude < 34)
            if (longitude > -76 && longitude < -64)
                /*
                 * 循环执行一次
                 * 都会往标准输出写入一条数据
                 * 所以下游的管道会立即接收处理这一条数据
                 * 不需要等到上游处理完全部的数据
                 */
                printf("%f %f %s\n",
                       latitude, longitude, info);
    return 0;
}