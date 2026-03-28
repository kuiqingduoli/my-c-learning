#include <stdio.h>

int main()
{
	int x,t,f;
	printf("已知存在一个函数f(x)\n");
	printf("请输入x\n");
	scanf("%d",&x);
	if(x<0){
	t=1;
	}else if(x==0){
	t=2;
	}else{
	t=3;
	}
	switch(t){
	case 1:
	    f=-1;
	    break;
	case 2:
		f=0;
		break;
	case 3:
		f=2*x;
		break;
	}
	printf("此时函数f的值为%d",f);
	return 0;
}
