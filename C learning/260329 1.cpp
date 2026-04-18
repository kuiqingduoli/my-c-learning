#include <stdio.h> 

void sayhello(char name[]);
int main()
{
	char username[20];
	printf("请输入您的姓名！\n");
	scanf("%s",username);
	sayhello(username);
	return 0;
}
void sayhello(char name[])
{
	printf("你好，%s！欢迎学习C语言函数!\n",name);
}
