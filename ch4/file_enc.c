/*
 * @author 刘昂林 
 * @date 2022/8/21
 * @brief 读取据进行加密
 */
#include <stdio.h>
#include "enc.h"

// extern 关键字共享变量
extern short enc_factor;

int main() {

    char msg[80];

    while (fgets(msg, 80, stdin)) {
        xor_enc(msg, enc_factor);
        puts(msg);
    }

    return 0;
}