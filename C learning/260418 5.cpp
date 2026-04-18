#include <stdio.h>

/*指针应用场景二b：
 *函数返回运算的状态，结果通过指针返回
 *常用的套路是让函数返回特殊的不属于有效范围内的值来表示出错：
   -0或-1
 *但是当任何数值都是有效的可能结果时，就得分开返回了(如上面所说函数返回运算的状态，结果通过指针返回)
 */ 
int divide(int a,int b,int *result);
int main()
{
	int a,b;
	int result;
	printf("请输入两个整数\n"); 
	scanf("%d %d",&a,&b);
	if(divide(a,b,&result))
	{
		printf("%d除以%d的结果为%d\n",a,b,result);
	}else
	{
		printf("无法计算！\n");
	}
	return 0;
	
}
int divide(int a,int b,int *result)
{
	int ret;
	if(b==0)
	{
		ret = 0;
	}else
	{
		*result=a/b;
		ret = 1;
	}
	return ret;
}
