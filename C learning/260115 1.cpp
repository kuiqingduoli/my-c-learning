#include <stdio.h>

int main()
{
	int num1=0,num2=0,num3=0,num4=0,num5=0;
	printf("请输入一串数字\n");
	scanf("%d",&num1);
	num4=num1; 
	do{
	num2=num1%10;
	num3=num1/10;
	num1=num3;
	num5=num5*10+num2;
	}while(num3!=0);
	printf("该数的倒序为%d\n",num5);
	if(num4==num5){
	printf("该数为回文数\n");
	}else{
	printf("该数不是回文数\n");
	}
	
	return 0;
}
