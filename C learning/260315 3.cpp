#include <stdio.h>

int main()
{
	int num=0;
    do{
	    printf("请输入一个正整数\n");
			scanf("%d",&num);
		}while(num<=100);
		printf("您输入的数大于100，程序结束\n")
		return 0;
}
