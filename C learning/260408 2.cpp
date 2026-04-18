#include <stdio.h>

int search(int x,int number[],int length); 
int main()
{
	char *name[]={"penny","nickel","dime","quarter","half-dollar"};
	int number[]={1,5,10,25,50};
	int x;
	printf("请输入一个硬币数额\n");
	scanf("%d",&x);
	int length=sizeof(number)/sizeof(number[0]);
	int found=search(x,number,length);
	if(found!=-1)
	{
		printf("%s\n",name[found]);
	}else
	{
		printf("Not Found!\n");
	}
}
int search(int x,int number[],int length)
{
	int ret=-1;
	int i;
	for(i=0;i<length;i++)
	{
		if(number[i]==x)
		{
			ret=i;
			break;
		}
	}
	return ret;
}
