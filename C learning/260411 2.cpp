#include <stdio.h> 

void f(int *p);
void j(int i);
int main()
{
	int i;
	i=6;
	int *p=&i;
	printf("i原先的值为：%d\n",i);
	f(&i);//调用里面不能写变量名，而是写地址 
	printf("经过f函数后i的值为：%d\n",i);
	j(i);
	printf("经过j函数后i的值为：%d\n",i);
}
void f(int *p)
{
	printf("i的地址为：%p\n",p); 
	printf("*p的值为：%d\n",*p);
	*p=25;//通过调用地址，可以修改i的值 
}
void j(int i)
{
	i=6;//调用的是i的值，在j函数里修改i的值不会影响到main函数里的i 
}
