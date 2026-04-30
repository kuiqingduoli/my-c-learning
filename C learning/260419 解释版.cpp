#include <stdio.h>

int main()
{
    /* ========== 1. 指针基础与数组访问 ========== */
    printf("========== 1. 指针基础与数组访问 ==========\n");
    char a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char *p = a;  // p指向数组a的首地址
    printf("p   = %p\n", p);
    printf("p+1 = %p\n", p + 1);  // 指针加法：移动sizeof(char)字节
    printf("sizeof(char) = %zu\n", sizeof(char));  // 使用%zu打印size_t类型
    
    // 通过指针访问数组元素
    printf("*(p+1) = %d\n", *(p + 1));  // 等价于a[1]
    printf("a[1]   = %d\n", a[1]);
    // 一般规则：*(p+n) 等价于 a[n]
    
    // 指针的负数索引和减法
    char *p1 = &a[5];
    printf("p1[-2] = %d\n", p1[-2]);      // 等价于a[3]
    printf("*(p1-2) = %d\n", *(p1 - 2));  // 同上
    char *p2 = &a[3];
    printf("p2 = %p\n", p2);
    printf("p2 - p = %td\n", p2 - p);  // 指针减法得到元素个数，使用%td打印ptrdiff_t
    
    /* ========== 2. 不同数据类型指针的算术运算 ========== */
    printf("\n========== 2. 不同数据类型指针的算术运算 ==========\n");
    int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *q = b;
    printf("q   = %p\n", q);
    printf("q+1 = %p\n", q + 1);  // 移动sizeof(int)字节
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("*(q+1) = %d\n", *(q + 1));
    printf("b[1]   = %d\n", b[1]);
    
    // 相同基类型指针的减法
    char *q1 = &a[3];
    printf("q1 = %p\n", q1);
    printf("q1 - p = %td\n", q1 - p);  // 同类型指针减法有意义
    
    /* ========== 3. 0地址和NULL指针  ========== */
    printf("\n========== 3. 0地址和NULL指针 ==========\n");
    /* 图片1要点：
       - 内存中存在0地址，但不能随意访问（通常受保护）。
       - 指针不应具有0值，但可以用0地址表示特殊情况。
       - NULL是一个预定义的符号，表示0地址（在C中通常定义为(void*)0）。
       - 编译器可能用NULL表示0地址，而非字面值0。
    */
    int *null_ptr = NULL;  // 使用NULL初始化指针，表示指针无效或未初始化
    printf("null_ptr = %p\n", (void*)null_ptr);
    if (null_ptr == NULL) {
        printf("null_ptr 是NULL指针，表示0地址，不能解引用。\n");
    }
    
    // 警告：不要解引用NULL指针，否则可能导致程序崩溃
    // int x = *null_ptr;  // 错误示例：不要这样做！
    
    // 指针初始化习惯：先初始化为NULL
    int *uninitialized_ptr = NULL;  // 良好习惯，避免野指针
    printf("uninitialized_ptr 初始化为NULL: %p\n", (void*)uninitialized_ptr);
    
    /* ========== 4. 指针类型转换和void*  ========== */
    printf("\n========== 4. 指针类型转换和void* ==========\n");
    /* 图片2要点：
       - void* 表示“指向未知类型对象的指针”，是通用指针类型。
       - 计算时与char*相同（但不相通，即void*不能直接解引用）。
       - 指针可以转换类型，转换的是看待数据的视角，而不是数据本身。
    */
    int i = 42;
    int *int_ptr = &i;
    printf("int_ptr 指向的整数: %d\n", *int_ptr);
    
    // 将int*转换为void*
    void *void_ptr = (void*)int_ptr;  // 显式类型转换
    printf("int_ptr 的值: %p\n", (void*)int_ptr);
    printf("void_ptr 的值: %p\n", void_ptr);
    // void_ptr 不能直接解引用，因为类型未知
    // 例如：int val = *void_ptr;  // 错误：void* 不能解引用
    
    // 将void*转换回int*
    int *int_ptr2 = (int*)void_ptr;  // 显式类型转换回来
    printf("通过int_ptr2 解引用: %d\n", *int_ptr2);
    
    // 示例：void* 可以指向任何类型，但必须转换后才能使用
    char c = 'A';
    void *generic_ptr = (void*)&c;  // 指向char
    char *char_ptr = (char*)generic_ptr;
    printf("通过generic_ptr 转换后获取字符: %c\n", *char_ptr);
    
    /* ========== 5. 指针运算 *p++  ========== */
    printf("\n========== 5. 指针运算 *p++ ==========\n");
    /* 图片3要点：
       - *p++ 表示：先取出p所指的数据，然后将p移动到下一个位置。
       - 优先级：++ 高于 *，所以等价于 *(p++)，而不是 (*p)++。
       - 常用于数组等连续空间操作，效率高。
       - 在某些CPU上可直接翻译成一条汇编指令。
    */
    int c_arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
    int *r = c_arr;
    
    // 使用循环遍历数组
    printf("遍历数组c_arr:\n");
    for (int i = 0; i < sizeof(c_arr) / sizeof(c_arr[0]); i++) {
        printf("%d ", c_arr[i]);
    }
    printf("\n");
    
    // 使用 *r++ 遍历数组直到遇到-1
    printf("使用 *r++ 遍历数组（直到-1）:\n");
    r = c_arr;  // 重置指针
    while (*r != -1) {
        printf("%d ", *r);  // 先输出当前值
        r++;  // 然后将r移动到下一个位置
        // 注意：这里没有使用 *r++ 在while条件中，但演示了类似思想
    }
    printf("\n");
    
    // 明确演示 *p++ 的行为
    r = c_arr;  // 重新指向数组开头
    printf("演示 *r++ 的步骤:\n");
    printf("初始 *r = %d\n", *r);
    int val = *r++;  // 等价于：val = *r; r++;
    printf("执行 val = *r++ 后:\n");
    printf("val = %d\n", val);
    printf("现在 *r = %d\n", *r);  // r已经移动到下一个元素
    
    // 另一个例子：在循环中使用 *p++
    printf("循环中使用 *p++ 打印数组:\n");
    r = c_arr;
    while (*r != -1) {
        printf("%d ", *r++);  // 输出当前值，然后指针自增
    }
    printf("\n");
    
    /* ========== 6. 类型不匹配的注意事项 ========== */
    printf("\n========== 6. 类型不匹配的注意事项 ==========\n");
    // 用户代码中注释的：q = p;  // 类型不同，不能直接这样写
    // 因为 q 是 int*，p 是 char*，直接赋值会导致类型不匹配
    // 必须显式转换：
    q = (int*)p;  // 但要注意：这可能引发对齐或类型解释问题
    printf("转换后 q = %p\n", (void*)q);
    // 但实际中，应避免不同类型指针间的随意转换，除非必要。
    
    return 0;
}
