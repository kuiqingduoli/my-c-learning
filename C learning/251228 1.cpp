#include <stdio.h>

int main()
{
	int year = 0,month = 0,day = 0,max_day = 0;
	printf("请输入日期(年月日)\n");
	scanf("%d %d %d",&year,&month,&day);
	if(month<1||month>12){
	printf("此日期不合法"); 
	return 0;
	}
	if(day<1||day>31){
	printf("此日期不合法");
	return 0;
	}
	max_day = 31;
	if(month==4||month==6||month==9||month==11){
	max_day = 30;
	}
	if(month==2){
	if(year%400==0||year%4==0&&year%100!=0){
	max_day = 29;
	}else{
	max_day = 28;
	}
	}
	if(day<=max_day){
	printf("此日期合法"); 
	}else{
	printf("此日期不合法");
	}
	return 0;
}
