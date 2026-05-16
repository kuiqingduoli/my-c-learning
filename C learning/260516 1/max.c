#include "max.h"  // 包含自定义的头文件

int gAll = 12;  // 全局变量定义，初始化为12

/**
 * 比较两个double类型的数，返回较大值
 * @param a 第一个双精度浮点数
 * @param b 第二个双精度浮点数
 * @return 较大的数
 */
double max(double a, double b)
{
    // 使用三元运算符判断并返回较大值
    return a > b ? a : b;
}
