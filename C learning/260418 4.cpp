#include <stdio.h> 

/*指针应用场景二:
 *函数返回多个值，某些值就只能通过指针返回 
 *传入的参数实际上是需要保存带回的结果的变量
 */ 
void search(int number[],int len,int *min,int *max);
int main()
{
	int number[]={5,9,18,26,32,41,55};
	int length=sizeof(number)/sizeof(number[0]);
	int min,max;
	search(number,length,&min,&max);
	printf("max=%d,min=%d",max,min);
	return 0;
}
void search(int number[],int len,int *min,int *max)
{
	*min=number[0];
	*max=number[0];
	int i;
	for(i=1;i<len;i++)
	{
		if(number[i]<*min)
		{
			*min=number[i];
		}else if(number[i]>*max)
		{
			*max=number[i];
		}
	}
}
