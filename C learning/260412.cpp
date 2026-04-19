#include <stdio.h>

int main()
{
    char c=1;
	char d='1';
	printf("c=%d\n",c);
	printf("c=%c\n",c);
	printf("d的ASCII码为：%d\n",d);
	printf("d='%c'\n",d);
	char a;
	printf("请输入a(a为数字)\n");
	scanf("%c",&a);
	printf("%c的ASCII码为：%d\n",a,a);
	printf("a='%c'\n",a);//用c读取数字，仍然是作为字符输入，当用d来输出时输出的不是输入的数字，而是这个数字字符的ASCII码 
	char e;
	printf("请输入e(e为字符)\n");
	scanf(" %c",&e); 
	printf("%c的ASCII码为：%d\n",e,e);
	printf("e='%c'\n",e);
	//字符计算 
	char f='A';
	f++;
	printf("%c\n",f);
	char g='Z'-'A';
	printf("%d\n",g);
	char h;
	scanf(" %c",&h);
	h=h+'a'-'A';//大写变小写 
	printf("%c\n",h);
	h=h+'A'-'a';//小写变大写 
	printf("%c\n",h);
	char b[20];
	scanf("%s",b);
	printf("%s,你好！",b);
}
