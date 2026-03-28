#include <stdio.h>

int main() 
{
	int n;
	printf("请输入一个非负整数\n");
	scanf("%d",&n);
	int j=n;
	int count=0;
	do
	{
		j/=10;
		count++;
   	}while(j!=0);
   	int t=1;
	while(count!=1)
	{
		t=t*10;
		count--;
	}
	int h;
	h=n; 
	while(t!=0)
	{
 		n%=t;
 		h/=t;
 		printf("%d ",h);
 		h=n;
		t/=10;
	}
	return 0;
}
