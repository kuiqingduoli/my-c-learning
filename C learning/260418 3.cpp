#include <stdio.h> 

//指针应用场景一:交换两个变量的值 
void swap(int *p,int *q);
int main()
{
	int a=5;
	int b=6;
	printf("交换前:a=%d,b=%d\n",a,b);
	swap(&a,&b);
	printf("交换后:a=%d,b=%d\n",a,b);
	return 0;
}
void swap(int *p,int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
}
