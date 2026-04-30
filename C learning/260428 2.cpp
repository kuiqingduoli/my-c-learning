#include <stdio.h>
#include <stdlib.h>
// 题目：编写一个函数，使用指针计算数组的平均值
float average(float *arr,int size);
// 题目：编写一个函数，用指针实现数组的逆序
void reverseArray(float *arr,int size);
int main()
{
	int size;
	printf("请输入数组大小\n");
	scanf("%d",&size);
	float *arr=(float *)malloc(size*sizeof(float));
	printf("请输入数组数据\n");
	int i;
	for(i=0;i<size;i++)
	{
		scanf("%f",&arr[i]);//在scanf中,float必须用 %f,而 double用 %lf
	}
	float result;
	result=average(arr,size);
	printf("数组的平均数为:%.2f\n",result);//在 printf中,float和 double都可以用 %f(因为float会自动提升为double)
	reverseArray(arr,size);
	free(arr);
	return 0;
}
float average(float *arr,int size)
{
	int i;
	float sum=0;
	float result;
	for(i=0;i<size;i++)
	{
		sum+=arr[i];
	}
	result=sum/size;
	return result;
}
void reverseArray(float *arr,int size)
{
	int i;
	for(i=size-1;i>=0;i--)
	{
		printf("%.0f ",arr[i]);
	}
}
