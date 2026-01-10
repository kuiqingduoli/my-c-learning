#include <stdio.h>

int main()
{
	int a = 0,b = 0,c = 0;
	printf("请输入三个不同的整数\n");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b&&b>c){
	printf("最大值为%d,最小值为%d",a,c);
	}else if(a>c&&c>b){
	printf("最大值为%d,最小值为%d",a,b);
	}else if(b>a&&a>c){
	printf("最大值为%d,最小值为%d",b,c);
	}else if(b>c&&c>a){
	printf("最大值为%d,最小值为%d",b,a);
	}else if(c>a&&a>b){
	printf("最大值为%d,最小值为%d",c,b);
	}else{
	printf("最大值为%d,最小值为%d",c,a);
	
	return 0;
	}
}
