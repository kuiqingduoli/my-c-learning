#include <stdio.h>

int main()
{
	const char *month[]={
	           "end",
			   "January",
	           "February",
			   "March",
			   "April",
			   "May",
			   "June",
			   "July",
			   "August",
			   "September",
			   "October",
			   "November",
			   "December"
			   };
	int number;
	int i;
	printf("请输入月份,输入0结束\n");
	scanf("%d",&number);
	while(number!=0)
	{
		if(number>=13||number<0)
		{
			printf("输入的月份无效！\n");
		}else
		{
			for(i=1;i<sizeof(month)/sizeof(month[0]);i++)
			{
				if(number==i)
				{
					printf("%s\n",month[i]);
					break;
				}	
			}
		}
		
		scanf("%d",&number);
	}
	printf("游戏结束\n");
	return 0;
}
