#include <stdio.h>

struct point 
{
	int x;
	int y;
};
void getstruct(struct point p);
void output(struct point p);
struct point p(void);
int main()
{
	struct point a;
	a.x=0,a.y=0;
	getstruct(a);
	output(a);
	a=p();
	printf("经过p之后：x=%d，y=%d\n",a.x,a.y);
	return 0;
}
void getstruct(struct point p)
{
	printf("请输入x和y\n");
	scanf("%d",&p.x);
	scanf("%d",&p.y);
	printf("getstruct中：x=%d，y=%d\n",p.x,p.y);
}
void output(struct point p)
{
	printf("output中：x=%d,y=%d\n",p.x,p.y);
}
struct point p(void)
{
	struct point p;
	printf("请输入x和y\n");
	scanf("%d",&p.x);
	scanf("%d",&p.y);
	return p;
}
