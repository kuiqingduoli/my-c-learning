#include <stdio.h>
#include <stdlib.h>

/*
 * 动态内存分配练习
 * 常见问题：
 * 1. 申请了没有free --> 长时间运行内存逐渐下降（内存泄漏）
 * 2. free过了再free --> 双重释放（double free）
 * 3. 地址变过了，直接去free --> 释放无效指针
 */

int main() 
{
    /********************* 第一部分：动态数组示例 *********************/
    int number;
    printf("请输入要创建的数组元素数量：\n");
    scanf("%d", &number);
    
    int *a;  // 声明指针，用于指向动态分配的内存
    
    /* 动态内存分配方法对比：
     * 1. 栈上数组（C99变长数组）：int a[number]; 
     *    优点：自动释放，不需要手动管理
     *    缺点：受栈空间限制，大数组可能导致栈溢出
     * 2. 堆上数组（malloc分配）：
     *    优点：空间大，生命周期由程序员控制
     *    缺点：需要手动释放，容易忘记
     */
    
    // 使用malloc分配内存
    // malloc返回void*，需要强制类型转换
    a = (int*)malloc(number * sizeof(int));
    
    // 检查内存是否分配成功
    if (a == NULL) {
        printf("内存分配失败！\n");
        return 1;  // 返回非0表示程序异常结束
    }
    
    printf("请输入%d个整数：\n", number);
    int i;
    for (i = 0; i < number; i++) {
        scanf("%d", &a[i]);  // 输入数据
    }
    
    printf("逆序输出：");
    for (i = number - 1; i >= 0; i--) {
        printf("%d ", a[i]);  // 逆序输出
    }
    printf("\n");
    
    // 释放动态分配的内存
    free(a);
    a = NULL;  // 好习惯：释放后将指针置为NULL，防止野指针
    
    /********************* 第二部分：内存分配测试 *********************/
    void *p;  // void* 是通用指针类型，可以转换为任何指针类型
    int cnt = 0;
    
    printf("\n测试系统可分配内存：\n");
    printf("每次尝试分配100MB内存...\n");
    
    /* malloc返回值的含义：
     * 成功：返回指向分配内存起始地址的指针
     * 失败：返回NULL
     */
    while ((p = malloc(100 * 1024 * 1024))) {  // 100MB = 100 * 1024KB * 1024B
        cnt++;
        printf("成功分配第%d个100MB块\n", cnt);
    }
    
    printf("总共分配了%d个100MB的内存块\n", cnt);
    printf("总计分配了%d00MB的空间\n", cnt);
    
    /* 注意：上面的while循环在分配失败时退出
     * 此时p为NULL，所以free(p)相当于free(NULL)
     */
    free(p);  // 安全：free(NULL)是允许的
    
    /********************* 第三部分：常见错误演示 *********************/
    printf("\n--- 常见错误示例（注释掉的代码是错误写法）---\n");
    
    void *q;
    
    // 正确：分配内存
    q = malloc(100 * 1024 * 1024);
    if (q != NULL) {
        printf("成功分配了100MB内存\n");
        
        // 正确：释放内存
        free(q);
        q = NULL;  // 好习惯
        printf("已正确释放内存\n");
    }
    
    /* 错误示例1：指针运算后free
     * q++;
     * free(q);  // 错误：q指向的已不是malloc返回的起始地址
     */
    
    /* 错误示例2：释放栈上变量的地址
     * int i = 5;
     * q = &i;
     * free(q);  // 错误：只能free从malloc/calloc/realloc分配的内存
     */
    
    // 正确：free(NULL)是安全的
    free(NULL);
    printf("free(NULL)执行成功，这是安全的\n");
    
    return 0;
}

/*
 * 内存管理要点总结：
 * 1. malloc后一定要检查返回值是否为NULL
 * 2. 配对使用：有malloc就要有对应的free
 * 3. 释放后立即将指针置为NULL
 * 4. 不要free非堆内存
 * 5. 不要free已释放的指针
 * 6. 不要释放指针运算后的地址
 * 
 * malloc函数原型：void* malloc(size_t size);
 * free函数原型：void free(void* ptr);
 * 
 * 其他相关函数：
 * 1. calloc: 分配并清零内存
 * 2. realloc: 调整已分配内存的大小
 */
