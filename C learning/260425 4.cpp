#include <stdio.h>
#include <stdbool.h>

struct date
{
	int month;
	int day;
	int year;
};
bool isLeap(struct date d);
int NumsOfDays(struct date d);
int main()
{
	struct date today;
	struct date tomorrow;
	printf("请输入今天日期(示例：1 1 2000)\n");
	scanf("%d %d %d",&today.month,&today.day,&today.year);
	if(today.day!=NumsOfDays(today))
	{
		tomorrow.day=today.day+1;
		tomorrow.month=today.month;
		tomorrow.year=today.year;
	}else if(today.month==12)
	{
		tomorrow.day=1;
		tomorrow.month=1;
		tomorrow.year=today.year+1;
	}else
	{
		tomorrow.day=1;
		tomorrow.month=today.month+1;
		tomorrow.year=today.year;
	}
	printf("明天的日期是:%d-%d-%d\n",tomorrow.month,tomorrow.day,tomorrow.year);
	return 0;
}
int NumsOfDays(struct date d)
{
	int days;
	const int daysPerMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(d.month==2&&isLeap(d))
	{
		days=29;
	}else
	{
		days=daysPerMonth[d.month-1];
	}
	return days;
}
bool isLeap(struct date d)
{
	bool leap=false;
	if((d.year%4==0&&d.year%100!=0)||d.year%400==0)
	{
		leap=true;
	}
	return leap;
}
