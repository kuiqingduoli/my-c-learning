#include <stdio.h>

int main()
{
	int num = 0;
	double money1 = 0;
	double money2 = 2000;
	int card_num = 0;
	do{
	printf("欢迎使用网上银行\n");
	printf("请选择您要使用的服务\n");
	printf("1.存入\n");
	printf("2.取款\n");
	printf("3.查询余额\n");
	printf("4.转账\n");
	printf("5.退卡\n");
	scanf("%d",&num);
	if(num == 1){
	printf("请输入您要存入的金额\n");
	scanf("%lf",&money1);
	money2 = money2 + money1;
	printf("已存入%.2f元，您现在的余额为%.2f元\n",money1,money2);
    }else if(num == 2){
    printf("请输入您要取出的金额\n");
    scanf("%lf",&money1);
    if(money1<=money2){
	money2 = money2 - money1;
    printf("已取出%.2f元,您现在的余额为%.2f元\n",money1,money2);
	}else{
	printf("您的余额不足！\n");
	}
	}else if(num ==3){
	printf("您的余额为%.2f元\n",money2);
	}else if(num ==4){
	printf("请输入您要转账的卡号\n");
	scanf("%d",&card_num);
	printf("请输入您要转入的金额\n");
	scanf("%lf",&money1);
	if(money1<=money2){
	money2 = money2 - money1; 
	printf("已向该卡转入%.2f元,您现在的余额为%.2f元",money1,money2);
	}else{
	printf("您的余额不足！");
	}
    }else if(num==5){
	}
	else{
    printf("输入错误，请输入1-5之间的数字\n");
	}
	}while(num != 5);
	printf("感谢您的使用！");
	return 0;
}
