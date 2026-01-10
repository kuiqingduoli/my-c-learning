#include <stdio.h>

int main()
{
	int number1 = 0,number2 = 0,number3 = 0;
	int change1 = 0,change2 = 0,change3 = 0;
	printf("请输入三个数字\n");
	scanf("%d %d %d",&number1,&number2,&number3);
	change1 = number1 + number2;
	change2 = number2 + number3;
	change3 = number1 + number3;
	if(change1>number3&&change2>number1&&change3>number2){
	if(number1==number2&&number1==number3){
	printf("等边三角形"); 
	}else if(number1==number2){
	printf("等腰三角形"); 
	}else if(number2==number3){
	printf("等腰三角形");
	}else if(number1==number3){
	printf("等腰三角形");
	}else if(number1!=number2,number1!=number3,number2!=number3){
	printf("不等边三角形"); 
	}
	}else{
	printf("抱歉，这三条边无法构成一个三角形");
	}
	
	return 0;
}
