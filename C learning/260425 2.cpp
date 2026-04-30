#include <stdio.h>

enum COLOR{RED,YELLOW,GREEN};//枚举 
enum NAME{Red,Yellow,Green,Numcolors};
enum Color{reD=1,yelloW=5,greeN=10};
int main()
{
	/* 常量符号化 */
	const int red=0;
	const int yellow=1;
	const int green=2;
	int color;
	char *colorname=NULL;
	printf("请输入您喜欢的颜色的代码\n");
	scanf("%d",&color);
	switch(color)
	{
		case red:colorname="red"; break;
		case yellow:colorname="yellow"; break;
		case green:colorname="green"; break;
		default:colorname="unknown"; break;
	}
	printf("您喜欢的颜色是:%s\n",colorname);
	/* 枚举 */  
	enum COLOR{RED,YELLOW,GREEN};
	printf("请输入您喜欢的颜色的代码\n");
	scanf("%d",&color);
	switch(color)
	{
		case RED:colorname="red"; break;
		case YELLOW:colorname="yellow"; break;
		case GREEN:colorname="green"; break;
		default:colorname="unknown"; break;
	}
	printf("您喜欢的颜色是:%s\n",colorname);
	/* 自动计数的枚举 */ 
	enum NAME{Red,Yellow,Green,Numcolors};
	char *colornames[Numcolors]={"red","yellow","green"};
	printf("请输入您喜欢的颜色的代码\n");
	scanf("%d",&color);
	if(color>=red&&color<Numcolors)
	{
		colorname=colornames[color];
	}else
	{
		colorname="unknown";
	}
	printf("您喜欢的颜色是:%s\n",colorname);
	/* 声明枚举量的时候可以指定值 */
	enum Color{reD=1,yelloW=5,greeN=10}; 
	printf("green code=%d",greeN);
	return 0;
}
