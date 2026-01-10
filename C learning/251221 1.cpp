#include <stdio.h>

int main()
{
	int hour1 = 0,hour2 = 0,minute1 = 0,minute2 = 0;
	
	printf("请输入时间1\n");
	scanf("%d %d",&hour1,&minute1);
	
	printf("请输入时间2(大于时间1)\n");
	scanf("%d %d",&hour2,&minute2);
	
	int change1 = hour2 - hour1,change2 = minute2 - minute1;
	if(change2>=0){
	printf("时间差为%时%d分\n",change1,change2);
	}else if(change1<=0){
	printf("错误！时间2应比时间1大"); 
	}else{
	printf("时间差为%d时%d分",change1 - 1,60 + change2);
	}
	return 0;
}
