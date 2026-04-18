#include <stdio.h>

void f(int a[],int length);
int main()
{
	int a[]={5,9,26,4,15,8};
	int length=sizeof(a)/sizeof(a[0]);
	printf("%d\n",sizeof(a));
	printf("%d\n",sizeof(a[0]));
	printf("%d\n",sizeof(a)/sizeof(a[0]));//数组做参数时，必须用额外的参数来表示数组大小，不能用sizeof来计算 
	printf("%d\n",length);
	f(a,length);
	int i=6;
	int *p=&i;
	printf("*p:%d\n",*p);
	printf("p[0]:%d\n",p[0]);//[]运算符可以对数组做，也可以对指针做 
	printf("*a:%d\n",*a);
	printf("a[0]:%d\n",a[0]);//*运算符可以对指针做，也可以对数组做 
	/*int b[] --> int * const b 
	数组变量是一个const的指针，所以不能被赋值 
	int *p=a 相当于int *p=&a[0]*/
	/*
	int a[5]={10,20,30,40,50}
	int *p=a
	*p=10
	p[0]=10
	*(p+1)=20
	*p[1]=20
	*/
}
void f(int a[]/* 相当于int*a */,int length)
{
	printf("%d\n",sizeof(a));
	printf("%d\n",sizeof(a[0]));
	printf("%d\n",sizeof(a)/sizeof(a[0]));
	printf("%d\n",length);
	a[0]=1000;
}
