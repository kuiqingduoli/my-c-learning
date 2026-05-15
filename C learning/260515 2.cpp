#include <stdio.h>
#include <stdlib.h>

/*--------返回指针的函数------------*/
/* 1.返回本地变量的地址是危险的 - 函数结束后内存被回收
 * 2.返回全局变量或者静态本地变量的地址是安全的
 * 3.返回在函数内malloc的内存是安全的，但容易造成内存泄漏
 * 4.最好的做法是返回传入的指针（调用者负责内存管理）
 */
int *A(void);      // 返回局部变量的地址 - 危险示例
void B(void);      // 演示栈帧重用
int *C(void);      // 返回静态本地变量地址 - 安全示例
int *D(void);      // 返回malloc内存的地址 - 需调用者释放
int *E(int *p);    // 返回传入的指针 - 最佳实践示例
void F(int *arr, int size);  // 另一个返回传入指针的示例

int main()
{
    printf("======= 返回指针的函数示例 =======\n\n");
    
    // 示例1: 返回局部变量地址 - 危险！
    printf("--- 示例1: 返回局部变量地址（危险！） ---\n");
    int *p = A();  // p指向已释放的栈内存
    printf("*p = %d\n", *p);  // 不可预测，可能是12也可能是垃圾值
    
    B();  // 调用B函数，重用栈空间
    
    printf("*p = %d (调用B后，原内存已被覆盖)\n", *p);
    printf("\n");
    
    // 示例2: 返回静态本地变量地址 - 安全
    printf("--- 示例2: 返回静态本地变量地址（安全） ---\n");
    int *q = C();  // q指向静态存储区的变量
    printf("*q = %d\n", *q);
    *q = 100;  // 可以安全修改
    printf("修改后 *q = %d\n", *q);
    printf("\n");
    
    // 示例3: 返回malloc内存地址 - 需调用者释放
    printf("--- 示例3: 返回malloc内存地址（需手动释放） ---\n");
    int *r = D();
    printf("*r = %d\n", *r);
    
    // 示例4: 返回传入的指针 - 最佳实践
    printf("\n--- 示例4: 返回传入的指针（最佳实践） ---\n");
    int x = 999;
    int *s = E(&x);
    printf("传入x的地址: %p\n", (void*)&x);
    printf("函数返回的地址: %p\n", (void*)s);
    printf("通过返回的指针访问值: *s = %d\n", *s);
    
    // 示例5: 返回传入的数组指针
    printf("\n--- 示例5: 返回传入的数组指针 ---\n");
    int arr[5] = {1, 2, 3, 4, 5};
    F(arr, 5);
    printf("调用F后数组内容: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 清理动态分配的内存
    free(r);
    r = NULL;  // 防止悬空指针
    
    printf("\n======= 示例结束 =======\n");
    return 0;
}

/* 函数A: 返回局部变量地址 - 危险示例！
 * 局部变量a在函数结束时被销毁，其地址不再有效
 * 返回这样的指针会导致未定义行为
 */
int *A(void)
{
    printf("返回局部变量的地址:\n");
    int a = 12;  // 局部变量，分配在栈上
    printf("a = %d\n", a);
    printf("&a = %p\n", (void*)&a);
    return &a;  // 危险！返回了即将被释放的内存地址
}

/* 函数B: 演示栈帧重用
 * 在A函数返回后，其栈空间被释放
 * 随后调用B函数，可能会重用同一块栈空间
 * 导致A返回的指针指向的内存被覆盖
 */
void B(void)
{
    printf("\nB函数被调用，可能会重用A函数的栈空间:\n");
    int b = 24;  // 可能分配在与A函数中a相同的位置
    printf("b = %d\n", b);
    printf("&b = %p\n", (void*)&b);
}

/* 函数C: 返回静态本地变量地址 - 安全示例
 * 静态本地变量存储在静态存储区，生命周期与程序相同
 * 函数结束后，变量依然存在
 */
int *C(void)
{
    printf("返回静态本地变量的地址:\n");
    static int c = 6;  // 静态本地变量，存储在静态存储区
    printf("c = %d\n", c);
    printf("&c = %p\n", (void*)&c);
    return &c;  // 安全：静态变量生命周期与程序相同
}

/* 函数D: 返回malloc分配的内存地址
 * malloc分配的内存位于堆上，需要手动释放
 * 返回这样的指针是安全的，但需要调用者记得释放
 * 否则会造成内存泄漏
 */
int *D(void)
{
    printf("返回malloc分配的内存地址:\n");
    int *d = (int *)malloc(sizeof(int));
    if (d == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    *d = 48;
    printf("*d = %d\n", *d);
    printf("d = %p (堆内存地址)\n", (void*)d);
    return d;  // 安全：堆内存需要手动释放
}

/* 函数E: 返回传入的指针 - 最佳实践
 * 接收外部传入的指针，返回同一个指针
 * 内存管理由调用者负责，函数不创建新内存
 * 这是一种安全的模式，避免了内存管理问题
 */
int *E(int *p)
{
    if (p == NULL) {
        return NULL;
    }
    printf("在E函数中: 接收到指针 %p，值为 %d\n", (void*)p, *p);
    *p += 100;  // 可以安全地修改指针指向的内容
    return p;  // 返回传入的指针
}

/* 函数F: 返回传入的数组指针
 * 对传入的数组进行操作，返回同一个指针
 * 这种模式常见于数组处理函数
 */
void F(int *arr, int size)
{
    if (arr == NULL || size <= 0) {
        return;
    }
    
    printf("在F函数中: 对数组每个元素加10\n");
    printf("原数组内容: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    for (int i = 0; i < size; i++) {
        arr[i] += 10;
    }
}
