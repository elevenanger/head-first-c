/*
 * @author 刘昂林 
 * @date 2022/8/21
 * @brief 使用异或对数据进行加密
 */
#include "enc.h"

short enc_factor = 31;

void xor_enc(char *message, short factor) {
    char c;
    while (*message) {
        *message = *message ^ factor;
        message ++;
    }
}