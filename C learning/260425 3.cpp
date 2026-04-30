#include <stdio.h>

/* 结构体声明：建议在函数外部声明结构体类型，这样可以在多个函数中使用 */
struct date
{
    int month;
    int day;
    int year;
};

int main()
{
    /* 方式1：定义结构体变量后，逐个成员赋值 */
    struct date today;
    today.month = 8;
    today.day = 31;
    today.year = 2026;

    /* 方式2：定义时直接初始化（顺序初始化） */
    struct date today1 = {8, 31, 2026};
    // struct date today2 = {.month=8, .year=2026}; // C99

    /* 打印结构体内容 */
    printf("today is %d-%d-%d\n", today.year, today.month, today.day);
    printf("today1 is %d-%d-%d\n", today1.year, today1.month, today1.day);
    // printf("today2 is %d-%d-%d\n", today2.year, today2.month, today2.day); // 如果启用today2

    /* 结构运算：使用复合字面量赋值整个结构体 */
    struct date today3;
    today3 = (struct date){8, 31, 2026};  // 复合字面量创建临时结构体并整体赋值
    printf("today3 is %d-%d-%d\n", today3.year, today3.month, today3.day);

    /* 结构运算：结构体之间直接赋值（整个结构复制，数组不支持此操作） */
    struct date today4;
    today4 = today3;  // 将today3的所有成员值复制到today4
    printf("today4 is %d-%d-%d\n", today4.year, today4.month, today4.day);

    /* 结构指针：结构变量名不是地址，必须使用&运算符获取地址 */
    struct date *pDate = &today;
    // struct date *pDate = today; // 错误：today是结构变量，不是指针
    printf("address of today is %p\n", (void*)pDate);  // 打印地址

    return 0;
}
