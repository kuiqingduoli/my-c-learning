#ifndef _MAX_H_     // 如果没有定义_MAX_H_，则定义它
#define _MAX_H_     // 防止头文件被重复包含的标准做法

// 函数声明
double max(double a, double b);

// 全局变量声明（使用extern关键字）
extern int gAll;    // 声明全局变量gAll，定义在max.c中

// 结构体声明
struct Node
{
    int value;      // 节点值
    char *name;     // 节点名称
};

#endif              // 结束条件编译
