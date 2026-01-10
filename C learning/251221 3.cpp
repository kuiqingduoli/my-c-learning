#include <stdio.h>

int main()
{
	double payment = 0,price = 0,remain = 0;
	printf("请输入购买的金额\n");
	scanf("%lf",&price);
	printf("请输入支付的金额\n");
	scanf("%lf",&payment);
	remain = payment - price;
	if(remain>=0){
	printf("找您%.2f元\n",remain);
	}else{
	printf("支付的金额不足！\n"); 
	}
	
	return 0;
}
