#include <stdio.h>

int main()
{
	int number;
	int money =1000;
	int money1;
	do{
	printf("欢迎使用网上银行！\n");
	printf("请选择您需要的服务\n");
	printf("1.取钱\n");
	printf("2.存钱\n");
	printf("3.转账\n");
	printf("4.查询余额\n");
	printf("5.退卡\n");
	scanf("%d",&number);
	switch(number){
		case 1:
			printf("请输入您要取出的金额\n");
		    scanf("%d",&money1);
		    if(money1<=0){
		    printf("取款金额不能小于或为零！\n");
			}else if(money1>money){
		    printf("您的余额不足！为%d元\n",money); 
			}else{
			money=money-money1;
		    printf("请收好您的现金,您现在的余额为%d元\n",money);
		    }
		    break;
		case 2:
			printf("请在下方存钱口放入现金\n");
			scanf("%d",&money1);
			money=money+money1;
			printf("您存入了%d元，您现在的余额为%d元\n",money1,money);
			break;
		case 3:
			printf("请输入您要转入的金额\n");
			scanf("%d",&money1);
			if(money1<=0){
		    printf("转账金额不能小于或为零！\n");
			}else if(money1>money){
		    printf("您的余额不足！为%d元\n",money);
			}else{
			money=money-money1;
			printf("您转入了%d元，您现在的余额为%d元\n",money1,money);
			}
			break;
		case 4:
			printf("您的余额为%d元\n",money); 
			break;
		case 5:
			printf("感谢您的使用,再见！\n");
			break;
		default:
			printf("系统错误，请再次尝试!\n");
			break;
	}
	}while(number!=5);
	return 0;
}
