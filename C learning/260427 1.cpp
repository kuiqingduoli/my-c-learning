#include <stdio.h>

// 结构体p：包含两个int类型成员
struct p 
{
    int x;  // 4字节
    int y;  // 4字节
};
// 结构体q：包含一个char和一个int类型成员
struct q
{
    char a;  // 1字节
    int b;   // 4字节
};

int main()
{
    // 测试结构体p
    struct p x={1,2}; 
    
    // 1. 打印结构体p实例x的大小
    printf("%d\n",sizeof(x));  // 预期输出：8（两个int，紧密排列）
    // 2. 打印结构体p类型的大小
    printf("%d\n",sizeof(struct p));  // 同上，应为8
    
    // 3. 获取结构体p成员的地址
    int *p = &x.x;  // 取成员x的地址
    int *q = &x.y;  // 取成员y的地址
    printf("%p\n",p);  // 打印成员x的地址
    printf("%p\n",q);  // 打印成员y的地址
    printf("%d\n",q-p);//得到元素个数 
    // 两个地址的差值应为4（因为int通常为4字节），说明它们连续排列
    
    // 测试结构体q
    struct q y={1,2};
    
    // 4. 打印结构体q实例y的大小
    printf("%d\n",sizeof(y));  // 输出：8（因为内存对齐，char后面有填充字节）
    // 5. 打印结构体q类型的大小
    printf("%d\n",sizeof(struct q));  // 同上，应为8（而不是1+4=5）
    
    // 6. 获取结构体q成员的地址
    char *a = &y.a;  // 取成员a的地址
    int *b = &y.b;  // 取成员b的地址
    printf("%p\n",a);  // 打印成员a的地址
    printf("%p\n",b);  // 打印成员b的地址
    printf("%d\n",(char*)b-a);//得到元素个数 
    // 两个地址的差值为4（而不是1），因为编译器在char后插入了填充字节
    // 以使int对齐到4字节边界
    
    return 0;
}
