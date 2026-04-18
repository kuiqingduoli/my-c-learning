#include <stdio.h>

int main()
{
	int i=0;
	const char *s="hello";
	const char *s1="hello";
	char s2[]="hello";
	printf("&i=%p\n",&i);
	printf("s =%p\n",s);
	printf("s1=%p\n",s1);
	printf("s2=%p\n",s2);
	//s[0]='b';s是只读的，不能写入，如果尝试写入会导致程序崩溃 
	//printf("%c\n",s[0]);
	s2[0]='b';
	printf("%c\n",s2[0]);
	//字符数组：char word[]={'H','e','l','l','o','!'}
	//字符串(同时也是字符数组)：char word[]={'H','e','l','l','o','!','\0'} 
	//char *name为字符串指针 
	const char *name1="Hello";//指向常量 
	char str[]="world";
	char *name2=str;//指向数组
	//name1[0] ='h';//不可以，因为指向常量，只读
	name2[0]='W';//可以修改，因为str是数组
	//char name为字符数组
	char name[]="hello";//等价于char name[6]={'h','e','l','l','o','\0'};
	name[0]='H';//可以修改
	//name="World";//错误！数组名不能重新赋值 
	//const char *name[]为指向常量的指针数组 
	const char *name3[]={"penny","nickel","dime"};
	/*等价于const char *name[3]；
	  name [0]="penny";
	  name [1]="nickel";
	  name [2]="dime";
	  是一个数组，每一个元素是指针
	  每个指针指向常量字符串
	  可以改变指针指向，不能通过指针修改字符串 
	*/
	name3[0]="quarter";//允许，改变了指针的指向
	//但不能通过指针修改字符串
	//name[0][0]='P'; //不允许，因为指向的是常量
	//等价于:*char[0]='P';//不允许 
	
}
