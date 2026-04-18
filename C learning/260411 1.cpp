#include <stdio.h>

int main(void)
{
	int a=6;
	double b=5;
	printf("sizeof(int)=%ld\n",sizeof(int));
	printf("sizeof(a)=%ld\n",sizeof(a));
	printf("sizeof(double)=%ld\n",sizeof(double));
	printf("sizeof(b)=%ld\n",sizeof(b));//int和double占的字节 
	printf("\n");
	printf("0x%x\n",&a);
	printf("%p\n",&a);
	/*int p;
	p=(int)&a;
	printf("0x%x\n",p);
	在64位系统过不了编译，在32位系统能过
	因为在64未系统中int占4个字节，地址占8个字节，转换过程中会有丢失
	32位系统中两个都占4个字节，没有丢失 
	*/
	printf("%lu\n",sizeof(int));
	printf("%lu\n",sizeof(&a));//通过转换系统检测字节数 
	printf("\n");
	//只能对变量取地址，像&(i++)不可以
	int i;
	int p;
	printf("%p\n",&i);
	printf("%p\n",&p);//相邻变量的地址
	printf("\n");
	int c[10];
	printf("%p\n",&c);
	printf("%p\n",c);
	printf("%p\n",&c[0]);
	printf("%p\n",&c[1]);//对数组取地址 
	return 0;
}
