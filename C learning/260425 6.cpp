#include <stdio.h> 

struct point
{
	int x;
	int y;
};
struct point *getstruct(struct point *p);
void output(struct point p);
void print(const struct point *p);
int main()
{
	struct point a={0,0};
	struct point *p=&a;
	getstruct(&a);
	printf("经过getstruct:x=%d,y=%d\n",a.x,a.y);
	output(*getstruct(&a));
	print(getstruct(&a));
	return 0;
}
struct point *getstruct(struct point *p)
{
	printf("请输入x和y\n"); 
	scanf("%d",&p->x);
	scanf("%d",&p->y);
	printf("getstruct中x=%d,y=%d\n",p->x,p->y);
	return p;
}
void output(struct point p)
{
	printf("output中x=%d,y=%d\n",p.x,p.y);
}
void print(const struct point *p)
{
	printf("x=%d,y=%d\n",p->x,p->y);
}
