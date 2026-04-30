#include <stdio.h>
#include <stdlib.h>
//动态内存分布 
int main()
/*常见问题:
 *申请了没有free -->长时间运行内存逐渐下降
 *free过了再free
 *地址变过了，直接去free
 */ 
{
	int number;
	printf("请输入数量\n");
	scanf("%d",&number);
	int *a;
	//int a[number]; //c99
	a=(int*)malloc(number*sizeof(int));
	int i;
	printf("请输入数字\n");
	for(i=0;i<number;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=number-1;i>=0;i--)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	free(a);
	void *p;
	int cnt=0;
	while( (p=malloc(100*1024*1024)) )
	{
		cnt++;
	}
	printf("分配了%d00MB的空间\n",cnt);
	free(p);
	void *q;
	q=malloc(100*1024*1024);
	//q++; //不可以，只能还申请来的空间的首地址 
	free(q);
	/*int i=5;
	q=&i;
	free(q);*/ //不可以 
	free(NULL);//可以 
	return 0;
}
