#include <stdio.h>

int main()
{
	double C = 0,F = 0;
	printf("请输入摄氏度\n");
	scanf("%lf",&C);
	if(C<-273.15){
	printf("请检查输入的摄氏度是否有误\n");
	}else{
	F = C * 1.8 + 32;
	printf("该摄氏度转化为华氏度为%.2f华氏度",F);
    }
	
	return 0;
}
