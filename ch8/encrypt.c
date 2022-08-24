/*
 * @author 刘昂林 
 * @date 2022/8/24
 * @brief 对数据加密
 */
#include "../head_files/encrypt.h"

void encrypt(char *message) {
    while (*message) {
        *message = *message ^ 31;
        message ++;
    }
}
