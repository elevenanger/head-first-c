/*
 * @date 2022/8/24
 * @brief 英国计算标准
 */
# include <stdio.h>

void display_calories(float weight, float distance, float coeff) {
    printf("Weight: %3.2f kg\n", weight / 2.2046);
    printf("Distance: %3.2f km\n", distance * 1.609344);
    printf("Calories burned: %4.2f cal\n", coeff * weight * distance);
}