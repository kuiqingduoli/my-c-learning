#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("========== C语言格式化输入输出完整示例 ==========\n");
    printf("========== 第一部分: printf格式化输出示例 ==========\n");

    // 1. 基本类型输出
    printf("\n1. 基本类型输出：\n");
    int intNum = 123;
    float floatNum = 3.14159;
    double doubleNum = 3.1415926535;
    char ch = 'A';
    char str[] = "Hello World";
    
    printf("整数: %d\n", intNum);
    printf("浮点数(默认6位小数): %f\n", floatNum);
    printf("双精度浮点数: %lf\n", doubleNum);
    printf("字符: %c\n", ch);
    printf("字符串: %s\n", str);
    
    // 2. 整数格式化
    printf("\n2. 整数格式化：\n");
    printf("十进制: %d\n", 255);
    printf("八进制: %o\n", 255);
    printf("十六进制(小写): %x\n", 255);
    printf("十六进制(大写): %X\n", 255);
    printf("无符号整数: %u\n", 255);
    printf("无符号整数(-1的补码): %u\n", -1);
    
    // 3. 对齐和宽度控制
    printf("\n3. 对齐和宽度控制：\n");
    printf("右对齐(默认): |%8d|\n", 123);
    printf("左对齐: |%-8d|\n", 123);
    printf("用0填充: |%08d|\n", 123);
    printf("指定宽度(字符串): |%15s|\n", "Hello");
    printf("左对齐(字符串): |%-15s|\n", "Hello");
    
    // 4. 符号控制
    printf("\n4. 符号控制：\n");
    printf("默认: %d\n", 100);
    printf("正数显示+号: %+d\n", 100);
    printf("负数: %d\n", -100);
    printf("正数前加空格: % d\n", 100);
    printf("负数前不加空格: % d\n", -100);
    
    // 5. 浮点数精度控制
    printf("\n5. 浮点数精度控制：\n");
    printf("默认6位小数: %f\n", 3.1415926535);
    printf("保留2位小数: %.2f\n", 3.1415926535);
    printf("保留5位小数: %.5f\n", 3.1415926535);
    printf("科学计数法(默认): %e\n", 1234.5678);
    printf("科学计数法(大写E): %E\n", 1234.5678);
    printf("科学计数法(2位小数): %.2e\n", 1234.5678);
    
    // 6. 智能格式(g/G)
    printf("\n6. 智能格式(g/G)：");
    printf("\n小数形式: %g\n", 123.456);
    printf("科学计数法形式: %g\n", 0.0000123456);
    printf("自动选择(大写G): %G\n", 123456789.0);
    
    // 7. 指针输出
    printf("\n7. 指针输出：\n");
    int x = 10;
    printf("变量x的值: %d\n", x);
    printf("变量x的地址: %p\n", (void*)&x);
    
    // 8. 计数功能(%n)
    printf("\n8. 计数功能(%%n)：\n");
    int numCount = 0;
    printf("%d%n\n",12345,&numCount);
    printf("有%d个数字\n", numCount);
    
    printf("\n========== 第二部分: scanf格式化输入示例 ==========\n");
    printf("注意: 每个示例运行后请按Enter键继续\n");
    
    // 清除输入缓冲区
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 1. 基本输入
    printf("\n1. 基本整数输入：\n");
    printf("请输入一个整数: ");
    int inputInt;
    scanf("%d", &inputInt);
    printf("你输入的是: %d\n", inputInt);
    
    // 清除输入缓冲区
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 2. 多个值输入
    printf("\n2. 多个值输入：\n");
    printf("请输入三个整数(用空格隔开): ");
    int a, b, c1;
    scanf("%d %d %d", &a, &b, &c1);
    printf("你输入的是: %d, %d, %d\n", a, b, c1);
    
    // 清除输入缓冲区
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 3. 浮点数输入
    printf("\n3. 浮点数输入：\n");
    printf("请输入一个浮点数: ");
    float inputFloat;
    scanf("%f", &inputFloat);
    printf("你输入的是: %.2f\n", inputFloat);
    
    // 清除输入缓冲区
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 4. 双精度浮点数输入
    printf("\n4. 双精度浮点数输入：\n");
    printf("请输入一个双精度浮点数: ");
    double inputDouble;
    scanf("%lf", &inputDouble);  // 注意: double必须用%lf
    printf("你输入的是: %.4lf\n", inputDouble);
    
    // 清除输入缓冲区
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 5. 字符输入
    printf("\n5. 字符输入：\n");
    printf("请输入一个字符: ");
    char inputChar;
    scanf("%c", &inputChar);
    printf("你输入的是: %c\n", inputChar);
    
    // 清除输入缓冲区
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 6. 字符串输入
    printf("\n6. 字符串输入(遇到空格停止)：\n");
    printf("请输入一个单词: ");
    char word[20];
    scanf("%s", word);
    printf("你输入的是: %s\n", word);
    
    // 清除输入缓冲区
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 7. 带限制的字符串输入(防止缓冲区溢出)
    printf("\n7. 带限制的字符串输入(最多读取4个字符)：\n");
    printf("请输入一个单词: ");
    char limitedWord[5];
    scanf("%4s", limitedWord);  // 最多读取4个字符
    printf("你输入的是: %s\n", limitedWord);
    
    // 清除输入缓冲区
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 8. 读取一整行(包含空格)
    printf("\n8. 读取一整行(包含空格)：\n");
    printf("请输入一句话: ");
    char sentence[50];
    scanf("%[^\n]", sentence);  // 读取直到遇到换行符
    printf("你输入的是: %s\n", sentence);
    
    // 清除输入缓冲区(这次不需要，因为上面已经读取了换行符)
    
    // 9. 赋值抑制符(*)
    printf("\n9. 赋值抑制符(*)示例：\n");
    printf("请输入日期(格式: 年-月-日): ");
    int year, day;
    scanf("%d-%*d-%d", &year, &day);
    printf("年: %d, 日: %d (月被跳过了)\n", year, day);
    
    // 清除输入缓冲区
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 10. 智能整数输入(%i)
    printf("\n10. 智能整数输入(%%i)：\n");
    printf("请输入一个整数(可以是十进制、八进制0开头、十六进制0x开头): ");
    int smartInt;
    scanf("%i", &smartInt);
    printf("你输入的是(十进制): %d\n", smartInt);
    
    // 清除输入缓冲区
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 11. 扫描集([])
    printf("\n11. 扫描集([])示例：\n");
    printf("只允许输入数字: ");
    char numbers[20];
    scanf("%[0-9]", numbers);
    printf("你输入的是: %s\n", numbers);
    
    // 清除输入缓冲区
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 12. 混合类型输入
    printf("\n12. 混合类型输入：\n");
    printf("请输入 姓名 年龄 工资: ");
    char name[20];
    int age;
    float salary;
    scanf("%s %d %f", name, &age, &salary);
    printf("姓名: %s, 年龄: %d, 工资: %.2f\n", name, age, salary);
    
    printf("\n========== 常见错误和注意事项 ==========\n");
    printf("1. scanf读取字符串时不需要&: char s[10]; scanf(\"%%s\", s);\n");
    printf("2. double类型必须用%%lf: double d; scanf(\"%%lf\", &d);\n");
    printf("3. 读取字符串时可以用%%Ns防止缓冲区溢出(N是最大字符数)\n");
    printf("4. %%c会读取空白字符(包括空格、回车等)\n");
    printf("5. %%s遇到空格、回车、Tab就会停止\n");
    printf("6. 使用%%[^\\n]可以读取包含空格的一整行\n");
    
    return 0;
}
