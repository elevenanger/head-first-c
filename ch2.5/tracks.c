/**
 * @file tracks.c
 * @brief 使用 string.h 标准库的函数处理字符串
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
# include<stdio.h>
# include<string.h>

int main() {
    /**
     * 第一个方括号用于访问所有字符串组成的数组
     * 第二个方括号用于访问每个单独的字符串，指定长度不超过 39
     * 每一个字符串都是一个数组
     * 这是一个数组的数组
     */
    char tracks[][40] = {
            "my heart will go on",
            "stuck in my heart",
            "hello",
            "dream of you"
    };

    printf("第 %i 首歌 : %s 第 %i 个字符 %c",
           1, tracks[1], 3, tracks[1][2]);

    for (int i = 0; i < 4; i++) {
        printf("第 %i 首歌 : %s\n", i, tracks[i]);
        char s1[] = "heart";
        /**
         * strstr(s0, s1)
         * 查找 s0 是否包含 s1
         */
        if (strstr(tracks[i], s1)) {
            printf("找到歌名中包含 \"heart\" 的音乐:%s \n", tracks[i]);
        }
    }
    return 0;
}