#include <stdio.h>
//目标：练习二维数组和定义 
int main()
{
	int i,j;
	int a[][3]={{1,2,3},{4,5,6}};
	int b[3][3]={{1,0,1},{0,1,0},{1,0,1}};//不能写b[0][0]=1这种写法
	//或者b[3][3]={[0][0]=1,[0][2]=1,[1][1]=1,[2][0]=1,[2][1]=1};(c99)
	int c[2][4]={{1,2,3,4}};
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
