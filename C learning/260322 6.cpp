#include <stdio.h>

int main()
{
	int count=0;
	for(int a=1;a<=9;a++)
	{
		for(int b=1;b<=9;b++)
		{
			for(int c=1;c<=9;c++)
			{
				if(a<b&&b<c)
				{
					if(c%2!=0)
					{
						int t=a*100+b*10+c;
						printf("%d\n",t);
						count++;
					}
				}
			}
		}
	}
	printf("共有%d个这样的数\n",count);
	return 0;
}
