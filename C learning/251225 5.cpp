#include <stdio.h>

int main()
{
    double height = 0,weight = 0,BMI = 0;
	printf("请输入您的身高(米)和体重(千克)\n");
	scanf("%lf %lf",&height,&weight);
	BMI = weight/(height * height);
	printf("您的BMI为:%.1f\n",BMI);
	if(BMI<18.5&&BMI>0){
	printf("偏瘦"); 
	}else if(BMI>=18.5&&BMI<24){
	printf("正常"); 
	}else if(BMI>=24&&BMI<28){
	printf("超重"); 
	}else if(BMI>=28){
	printf("肥胖");
	}else{
	printf("请检查您输入的数据是否有误"); 
	}
	return 0;
}
