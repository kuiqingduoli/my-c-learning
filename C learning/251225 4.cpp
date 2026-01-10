#include <stdio.h>

int main()
{
    double height = 0,weight = 0,BMI = 0;
	printf("请输入您的身高(米)和体重(千克)\n");
	scanf("%lf %lf",&height,&weight);
	BMI = weight/(height * height);
	printf("您的BMI为:%.1f",BMI);
	
	return 0;
}
