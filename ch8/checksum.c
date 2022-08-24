/*
 * @author 刘昂林 
 * @date 2022/8/24
 * @brief 计算校验和
 */
#include "../head_files/checksum.h"

int checksum(char *message) {
    int c = 0;
    while (*message) {
        c += c ^ (int)(*message);
        message ++;
    }
    return c;
}