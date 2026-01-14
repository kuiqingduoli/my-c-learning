#include <stdio.h>

int main()
{
	int n=52;
	int k=0,q=0;
	printf("猜数字(1-100的整数)\n");
	do{
	scanf("%d",&k);
	if(n>k){
	printf("太小了！\n");
	q++;
	}else if(n<k){
	printf("太大了！\n");
	q++;
	}
	}while(n!=k);
	printf("恭喜！猜对了！共猜了%d次\n",q);
	
	return 0;
}
