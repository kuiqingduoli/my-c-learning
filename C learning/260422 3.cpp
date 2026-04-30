#include <stdio.h>
#include <stdlib.h> 

int main()
{
    /* 拓展: 指向指针的指针  */
    
    // 情况1: 指向字符串指针的指针
    char *str = "Hello World";  // str是一个指针，指向字符串字面量
    char **ptr1 = &str;         // ptr1是指向str的指针
    
    printf("指向指针的指针ptr1:\n");
    printf("str 的内容: %s\n", str);
    printf("str 的地址: %p\n", (void*)&str);
    printf("ptr1的值(指向str的地址): %p\n", ptr1);
    printf("*ptr1的值(str的值): %p\n", *ptr1);
    printf("**ptr1(第一个字符): %c\n", **ptr1);
    printf("*ptr1(字符串): %s\n", *ptr1);
    printf("\n");
    
    // 情况2: 指向指针数组首元素的指针
    char *str_array[] = {"First", "Second", "Third"};  // 字符串指针数组
    char **ptr2 = str_array;  // ptr2指向str_array[0]，而str_array[0]本身是一个指针
    
    printf("指向指针数组首元素的指针ptr2:\n");
    for (int i = 0; i < 3; i++) {
        // ptr2 + i 移动到第i个指针的地址
        // *(ptr2 + i) 获取第i个指针指向的字符串
        printf("ptr2[%d] 或 *(ptr2+%d) = %s\n", i, i, *(ptr2 + i));
    }
    printf("\n");
    
    // 情况3: 动态分配的字符串数组
    char **ptr3 = (char**)malloc(3 * sizeof(char*));  // 分配3个指针的空间
    if (ptr3 != NULL) {
        ptr3[0] = "Dynamic";   // 指针指向字符串字面量
        ptr3[1] = "Memory";
        ptr3[2] = "Example";
        
        printf("动态分配的字符串指针数组ptr3:\n");
        for (int i = 0; i < 3; i++) {
            printf("%s ", ptr3[i]);
        }
        printf("\n");
        
        free(ptr3);  // 释放内存
    }
    
    return 0;
}
