/*题目：判断一个字符串是否是回文（忽略大小写和空格）
int isPalindrome(char* s) 
  {
    // 你的代码
  }
 *示例："A man a plan a canal Panama" -> 是回文
 *考察：双指针、字符串处理
 */
 
//错误版: 
#include <stdio.h>
#include <string.h>

int isPalindrome(char* s);
int main()
{
	char s[20]; 
	printf("请输入一个字符串(小于20个字符)\n");
	scanf("%19s",s);
	int ispalindrome=isPalindrome(s);
	if(ispalindrome)
	{
		printf("是回文\n");
	}else
	{
		printf("不是回文\n");
	}
	return 0;
}
int isPalindrome(char* s)
{
	char p[20];
	int len=strlen(s);
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		p[len-1-i]=s[i];
	}
	p[i]='\0';
	int result=strcmp(s,p);
	int ispalindrome=0;
	if(result==0)
	{
		ispalindrome=1;
	}
	return ispalindrome;
}
/* 1.scanf在遇到空格试停止读取，如输入 a man只读入了 a 
   2.未忽略大小写
   3.内存浪费，创建了额外数组，但用双指针法可以节省空间完成 
*/

//正确版:
#include <stdio.h>
#include <string.h>

// 函数声明
int isPalindrome(char *s);
int isAlnumCustom(char c);  // 自定义判断是否为字母数字
char toLowerCustom(char c); // 自定义转小写

int main()
{
    char s[100];
    char c;
    
    printf("请输入一串字符串(小于100个字符):\n");
    
    // 使用fgets更安全，可以读取包含空格的整行
    fgets(s, sizeof(s), stdin);
    
    // 移除末尾的换行符
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') {
        s[len-1] = '\0';
    }
    
    if (isPalindrome(s))
    {
        printf("'%s' 是回文\n", s);
    }
    else
    {
        printf("'%s' 不是回文\n", s);
    }
    
    return 0;
}

// 判断字符是否为字母或数字（根据题目通常要求）
int isAlnumCustom(char c)
{
    int ret=0;
    if ((c >= 'A' && c <= 'Z') || 
        (c >= 'a' && c <= 'z') || 
        (c >= '0' && c <= '9')) {
        ret=1;
    }
    return ret;
}

// 将字符转为小写
char toLowerCustom(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');  // 更清晰的写法
    }
    return c;
}

// 判断是否为回文
int isPalindrome(char *s)
{
    if (s == NULL || s[0] == '\0') {
        return 1;  // 空字符串或 NULL视为回文
    }
    
    char *left = s;
    char *right = s + strlen(s) - 1;  // 直接计算，更简洁
    
    while (left < right)
    {
        // 跳过非字母数字字符
        while (left < right && !isAlnumCustom(*left)) {
            left++;
        }
        while (left < right && !isAlnumCustom(*right)) {
            right--;
        }
        
        // 如果跳过后 left >= right，说明中间都是非字母数字
        if (left >= right) {
            break;
        }
        
        // 比较字符（忽略大小写）
        if (toLowerCustom(*left) != toLowerCustom(*right)) {
            return 0;  // 不是回文
        }
        
        left++;
        right--;
    }
    
    return 1;  // 是回文
}
