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
	printf("请输入月份\n");
	scanf("%d",&number);
	if(number>=1&&number<=12)
	{
		printf("对应月份的英文为:%s",month[number]);
	}else
	{
		printf("输入的月份有误！\n");
	}
	return 0;
}
