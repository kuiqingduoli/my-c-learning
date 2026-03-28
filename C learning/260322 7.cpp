#include <stdio.h>

int main()
{
	for(int a=1;a<=9;a++)
	{
		for(int b=0;b<=9;b++)
		{
			for(int c=0;c<=9;c++)
			{
				for(int d=0;d<=9;d++)
				{
					int t=a*10+b+c*10+d;
					if(t==16||t==25||t==36||t==49||t==64||t==81)
					{
						int h=a*1000+b*100+c*10+d;
						printf("%d ",h);
					}
				}
			}
		}
	}
}
