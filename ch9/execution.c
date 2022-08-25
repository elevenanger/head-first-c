/*
 * @author 刘昂林 
 * @date 2022/8/25
 * @brief 使用 exec() 函数来替换当前进程
 */
#include <unistd.h>

char *my_args = "-ef";

void process_status() {
    execl("/bin/ps", "/bin/ps", "-ef", NULL);
}

void process_status_with_arg() {
    /*
     * execv() 和 execvP() 接收参数向量或者参数数组
     * P 指在 PATH 中寻找可执行的程序
     */
//    execv("/bin/ps", &my_args);
    execvP("ps", "ps", &my_args);
}
void network_info() {
    /*
     * excel() 指定执行程序和参数 以 NULL 结尾告诉函数没有其它参数了
     * excelp() 在 PATH 中查找程序
     * excele()
     */

    execl("/sbin/ifconfig", "/sbin/ifconfig", "-a", NULL);
}

int main() {
    process_status();
//    process_status();
//    network_info();
    return 0;
}