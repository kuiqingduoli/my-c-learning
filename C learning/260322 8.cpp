#include <stdio.h>

int main() 
{
	int count =0;
	for(int x=1;x<15;x++)
	{
		for(int y=1;y<15;y++)
		{
			for(int z=1;z<15;z++)
			{
				int t=x+y+z;
				int h=2*x+3*y+4*z;
				if(t==15&&h==40)
				{
					printf("x为%d，y为%d，z为%d\n",x,y,z);
					count++;
				}
			}
		}
	}
	printf("一共有%d个解\n",count);
}
