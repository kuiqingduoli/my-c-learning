#include <stdio.h> 
//目标：输入n个数字(小于100)，按照从小到大的顺序输出 
int main()
{
	int n,i,j,temp;
	int number[100];
	printf("请输入数字个数(小于100)\n");
	scanf("%d",&n);//输入数字总数 
	printf("请输入数字\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&number[i]);
	} //输入数字并存入数组 
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(number[n-1-i]<number[j])
			{
				temp=number[n-1-i];
				number[n-1-i]=number[j];
				number[j]=temp;
			}//排序 
		}
	}
	for(i=0;i<n;i++)
	{ 
		printf("%d ",number[i]);//输出排序好的数 
    }
}
