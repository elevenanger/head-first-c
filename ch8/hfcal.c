/*
 * @author 刘昂林 
 * @date 2022/8/24
 * @brief 计算卡路里
 */
#include <stdio.h>
#include "../head_files//hfcal.h"

/**
 * 计算消耗的卡路里
 * @param weight 体重
 * @param distance 距离
 * @param coeff 系数
 */
void display_calories(float weight, float distance, float coeff) {
    printf("体重：%.2f\n", weight);
    printf("距离：%.2f\n",weight);
    printf("消耗的卡路里：%.2f\n", coeff * weight * distance);
}
