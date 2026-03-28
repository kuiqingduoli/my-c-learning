#include <stdio.h>

int main()
{
	int t=0;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
		    t+=1;
			printf("%d ",t);
		}
		printf("\n");
	}
	return 0;
}
