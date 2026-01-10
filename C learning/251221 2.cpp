#include <stdio.h>

int main()
   {
	int hour1 = 0,hour2 = 0,minute1 = 0,minute2 = 0;
	
	printf("请输入时间1\n");
	scanf("%d %d",&hour1,&minute1);
	
	printf("请输入时间2\n");
	scanf("%d %d",&hour2,&minute2);
	
	int total_minute1 = hour1 * 60 + minute1;
	int total_minute2 = hour2 * 60 + minute2;
	
	int diff_minute = 0;
	if(total_minute1>=total_minute2){
	diff_minute = total_minute1 - total_minute2;
	}else{
	diff_minute = total_minute2 - total_minute1; 
	}
	int hour = diff_minute / 60;
	int minute = diff_minute % 60;
	
	printf("时间差为%d时%d分",hour,minute) ;
	
	return 0;
    }
