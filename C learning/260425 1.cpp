#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	/* strchr: 在字符串中查找字符
	 * 寻找字符在字符串中从左往右第一次出现的位置
	 * 返回的是指针，指向那个字符
	 */
	char a[] = "Hello";
	
	// 查找第一个'l'
	char *p = strchr(a, 'l');
	if(p != NULL)
	{
		printf("p = %s\n", p);//注释见最下方 
		
		// 查找第二个'l'（从第一个'l'后面开始找）
		char *p1 = strchr(p + 1, 'l');
		if(p1 != NULL)
		{
			printf("p1 = %s\n", p1);
		}else
		{
			printf("没有找到第二个'l'\n");
		}
		
		// 把p后面的字符拷贝到一个新指针
		char *t = (char*)malloc((strlen(p) + 1) * sizeof(char));
		if(t != NULL)
		{
			strcpy(t, p);
			printf("t = %s\n", t);
			free(t);
			t = NULL;
		}else
		{
			printf("内存分配失败\n");
		}
		
		// 把p前面的字符拷贝到一个新指针
		char *t1 = NULL;
		char c = *p;  // 保存当前字符
		*p = '\0';    // 临时将第一个'l'替换为字符串结束符
		
		t1 = (char*)malloc((strlen(a) + 1) * sizeof(char));
		if(t1 != NULL)
		{
			strcpy(t1, a);
			printf("t1 = %s\n", t1);
			free(t1);
			t1 = NULL;
		}else
		{
		    printf("内存分配失败\n");	
		} 
		
		*p = c;  // 恢复原来的字符
	}else
	{
		printf("没有找到第一个'l'\n");
	}
	
	/* strrchr: 在字符串中查找字符
	 * 寻找字符在字符串中从右往左第一次出现的位置
	 * 返回的是指针，指向那个字符
	 */
	char b[] = "Hello";  // 重新初始化字符串
	
	char *q = strrchr(b, 'l');
	if(q != NULL)
	{
		printf("q = %s\n", q);
		
		// 寻找前一个'l'（从字符串开头到q-1的位置查找）
		char temp = *q;  // 保存当前字符
		*q = '\0';       // 临时修改，使查找范围不包括当前字符
		
		char *q1 = strrchr(b, 'l');  // 在修改后的字符串中查找
		*q = temp;  // 恢复原来的字符
		if(q1 != NULL)
		{
			printf("q1 = %s\n", q1);
		}
		else
		{
			printf("没有找到第二个'l'\n");
		}
		
		
		// 把q后面的字符拷贝到一个新指针
		char *s = (char*)malloc((strlen(q) + 1) * sizeof(char));
		if(s != NULL)
		{
			strcpy(s, q);
			printf("s = %s\n", s);
			free(s);
			s = NULL;
		}else
		{
		    printf("内存分配失败\n");	
		} 
		
		// 把q前面的字符拷贝到一个新指针
		char *s1 = NULL;
		*q = '\0';  // 临时修改
		
		s1 = (char*)malloc((strlen(b) + 1) * sizeof(char));
		if(s1 != NULL)
		{
			strcpy(s1, b);
			printf("s1 = %s\n", s1);
			free(s1);
			s1 = NULL;
		}else
		{
		    printf("内存分配失败\n");	
		} 
		
		*q = temp;  // 恢复原来的字符
	}else
	{
		printf("没有找到第一个'l'\n");
	}
	/* 用 p 和 *p及 %s和 %c的区别 */
    char word[] = "Hello";
    // strchr函数在word中查找第一个字符'l'的地址
    // 返回的是一个指针（地址），而不是具体的字符
    char *p1 = strchr(word, 'l');  // p1是一个指针，指向word中的第一个'l'
    
    // 情况1：使用%s格式符打印字符串
    // %s需要一个字符指针（地址）作为参数
    // 它会从这个地址开始，一直打印到字符串结束符'\0'
    printf("使用p（指针/地址）:\n");
    printf("%s\n", p1);  // 输出：llo（从第一个'l'开始到字符串末尾）
    
    // 情况2：使用%c格式符打印单个字符
    // 此时需要对指针p解引用，获取它指向的字符
    printf("使用*p（解引用获取字符）:\n");
    printf("%c\n", *p1);  // 输出：l（单个字符）
    
    // 常见错误示例（取消注释会导致问题）：
    // printf("%s\n", *p);  // 错误！%s需要地址，但*p是字符'l'
    // 这可能会导致程序崩溃或输出乱码，因为编译器试图将'l'的ASCII码值(108)当作地址访问
    
    return 0; 
}
