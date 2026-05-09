/* 题目：编写函数，反转一个字符串（原地修改）
*void reverseString(char* s) 
  {
    // 你的代码
  }
*示例：输入"hello" -> 反转后"olleh"
*考察：指针操作、字符串、数组
*/

//版本 1: 
#include <stdio.h>

void reverseString(char *s,char *p);
int main()
{
	char s[20];
	printf("请输入一个单词(不超过20个字符)\n");
	scanf("%19s",s);
	char *p=s;
	reverseString(s,p);
	return 0;
}
void reverseString(char *s,char *p)
{
	while(*p)
	{
		p++;
	}
	p-=1;
	while(*p)//有问题！ 
	{
		printf("%c ",*p);
		p--;
	}
	return 0;
}
/*问题 1： 
	 *当从最后一个字符开始打印，打印完第一个字符后，
 	 *p--会指向第一个字符前面的内存地址 
	 *这个地址可能是0，可能是随机值 
	 *如果不是0，循环会继续，导致越界访问，程序崩溃
	*/
	/*问题 2： 
	 *题目要求反转字符串，理解成了逆序打印，并没有修改字符串
	 */
	/*问题 3：
	 *函数参数设计冗余
	 */ 
	 
//版本 2：
#include <stdio.h> 

void reverseString(char *s);
int main()
{
	char s[20];
	printf("请输入一个单词(不超过20个字符)\n");
	scanf("%19s",s);
	printf("逆序输出为:\n");
	reverseString(s);
	return 0;
}
void reverseString(char *s)
{
	int i=0;
	while(s[i]!='\0')
	{
		i++;
	}
	while(i>=0)
	{
		printf("%c ",s[i]);
		i--;
	}
}
    /*优点：修复了参数冗余的问题
	 *缺点：依旧不属于反转字符串
	 */
	 
//版本 3： 
#include <stdio.h>

void reverseString(char *s);
int main()
{
	char s[20];
	printf("请输入一个单词(不超过20个字符)\n");
	scanf("%19s",s);
	reverseString(s);
	printf("反转后为:%s\n",s);
	return 0;
}
void reverseString(char *s)
{
	char *left=s; //指向开头 
	char *right=left;
	char temp;
	while(*right!='\0')
	{
		right++;
	}
	right--;//指向最后一个字符 
	while(left<right)//当左指针在右指针左边时 
	{
		temp=*left;
		*left=*right;
		*right=temp;//交换两个字符 
		left++;
		right--;//指针向中间移动 
	}
}

//版本 4：
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

char *reverseString(char *s);
int main()
{
	char s[20];
	printf("请输入一个单词(不超过20个字符)\n");
	scanf("%19s",s);
	char *p=reverseString(s);
	printf("反转后为:%s\n",p);
	free(p);
	return 0;
}
char *reverseString(char *s)
{
    if (s == NULL) //防御性编程
    return NULL;
	int len=strlen(s);
	char *p=(char*)malloc(sizeof(char)*(len+1));
	if (p == NULL) //内存分配失败检查
    {
        printf("内存分配失败\n");
        exit(1);
    }
	for(int i=0;i<len;i++) 
    {
        p[i]=s[len-1-i];
    }
	p[len]='\0';
	return p;
}

	 
