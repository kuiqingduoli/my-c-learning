#include <stdio.h>

int main()
{
	char a[]={0,1,2,3,4,5,6,7,8,9};
	char *p=a;
	printf("p  =%p\n",p);
	printf("p+1=%p\n",p+1);
	printf("sizeof(char)=%d\n",sizeof(char));
	//*p=a[0],*(p+1)=a[1]
	printf("*(p+1)=%d\n",*(p+1));
	printf("a[1]=%d\n",a[1]);
	//*(p+n)=a[n]
	char *p1=&a[5];
	printf("p1[-2]=%d\n",p1[-2]);
	printf("*(p1-2)=%d\n",*(p1-2));
	char *p2=&a[3];
	printf("p2=%p\n",p2);
	printf("p2-p=%d\n",p2-p);
	int b[]={0,1,2,3,4,5,6,7,8,9};
	int *q=b;
	printf("q  =%p\n",q);
	printf("q+1=%p\n",q+1);
	printf("sizeof(int)=%d\n",sizeof(int));
	printf("*(q+1)=%d\n",*(q+1));
	printf("b[1]=%d\n",b[1]);
	char *q1=&a[3];
	printf("q1=%p\n",q1);
	printf("q1-p=%d\n",q1-p);
	int c[]={0,1,2,3,4,5,6,7,8,9,-1};
	int i;
	int *r=c;
	for(i=0;i<sizeof(c)/sizeof(c[0]);i++)
	{
		printf("%d ",c[i]);
	}
	printf("\n");
	while(*r!=-1)
	{
		printf("%d ",*r);
		*r++;
	}
	//q=p; //类型不同，不能直接这样写 
	
	return 0;
}
