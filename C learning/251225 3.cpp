#include <stdio.h>

int main()
{
	int grade = 0;
	printf("请输入一个0-100的分数\n");
	scanf("%d",&grade);
	if(grade>=90&&grade<=100){
	printf("等级为A");
	}else if(grade>=80&&grade<=89){
	printf("等级为B");
	}else if(grade>=70&&grade<=79){
	printf("等级为C");
	}else if(grade>=60&&grade<=69){
	printf("等级为D");
	}else if(grade>=0&&grade<=59){
	printf("等级为F");
	}else{
	printf("请检查输入的分数是否有误"); 
	}
	
	return 0;
}
