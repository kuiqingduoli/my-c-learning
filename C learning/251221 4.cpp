#include <stdio.h>

int main()
{
	int number = 0;
	printf("请输入一个整数\n");
	scanf("%d",&number);
	if(number%2 == 0){
	printf("该数为偶数\n");
	}else{
	printf("该数为奇数\n");
	}
	
	return 0;
}
