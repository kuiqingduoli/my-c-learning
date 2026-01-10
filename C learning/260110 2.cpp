#include <stdio.h>

int main()
{
	double num1 = 0,num2 = 0,result = 0;
	char sign;
	char jieshu;
	do{ 
    printf("请输入一个数字\n");
	scanf("%lf",&num1) ;
	printf("请再输入一个数字\n");
	scanf("%lf",&num2);
	printf("请输入运算符号(+,-,*,/)\n");
	scanf("%s",&sign);
	if(sign=='+'){
	result = num1 + num2;
	printf("%f\n",result);
	}else if(sign=='-'){
	result = num1 - num2;
	printf("%f\n",result);
	}else if(sign=='*'){
	result = num1 * num2;
	printf("%f\n",result);
	}else if(sign=='/'){
    if(num2==0){
    printf("被除数不能为零\n");
	}else{
	result =  num1 / num2;
	printf("%f\n",result);
	}
	}else{
	printf("请检查输入的运算符号是否有误\n");
	}
	printf("按n结束，按其他键或回车键继续\n");
	getchar();
	jieshu = getchar();
    }while(jieshu!='n'&&jieshu!='N');
    
	return 0;
	
}
