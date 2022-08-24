/*
 * @date 2022/8/24
 * @brief 信使
 *
 * gcc -I ../head_files messenger.c
 * ../object_files/encrypt.o
 * ../object_files/checksum.o
 * -o messenger
 * gcc -I 从指定目录查找头文件
 *
 * ar -rcs ../lib/libhfsecurity.a
 * ../object_files/encrypt.o
 * ../object_files/checksum.o
 *
 * ar -rcs 创建存档
 * 存档需要以 lib 开头 .a 格式
 * 两个 .o 文件是保存在存档中的文件
 *
 * gcc messenger.c -L ../lib
 * -l hfsecurity
 * -o messenger
 *
 * -L 从指定路径查找库文件
 * -l hfsecurity 指定库文件，不需要 lib 前缀和 .a 后缀
 *
 * gcc -shared hfcal.o -o ../share/libhfcal.dylib
 * -shared 选项将 .o 文件转换为动态库
 * 编译器在创建动态库的时候会将库的名字保存在文件中
 * libhfcal.dylib 会记录它的库叫做 hfcal
 * 一旦用某个名字编译了动态库就不能再修改文件名了
 * 创建了动态库就可以像静态库一样使用它
 * 动态库是动态的
 * 编译器不会再可执行文件中包含库代码
 * 而是插入一段占位符代码在运行时链接库文件
 * 动态库创建后可以在运行时重新编译动态改变程序的行为
 */
#include <stdio.h>
#include "../head_files/encrypt.h"
#include "../head_files/checksum.h"

int main() {
    char s[] = "Please wait for me!";
    encrypt(s);
    printf("encrypted : %s\n", s);
    printf("checksum : %i \n", checksum(s));

    encrypt(s);
    printf("decrypted : %s\n", s);
    printf("checksum : %i \n", checksum(s));
}