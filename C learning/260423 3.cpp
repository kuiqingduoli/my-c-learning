#include <stdio.h>

int main()
{
	const char *month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int number[]={1,2,3,4,5,6,7,8,9,10,11,12};
	struct
	{
		int number;
		const char *month;
	}English[]=
	{
		{1,"January"},
		{2,"February"},
		{3,"March"},
		{4,"April"},
		{5,"May"},
		{6,"June"},
		{7,"July"},
		{8,"August"},
		{9,"September"},
		{10,"October"},
		{11,"November"},
		{12,"December"}
	};
	int n;
	printf("请输入月份\n");
	scanf("%d",&n);
	int i;
	int found=0;
	for(i=0;i<sizeof(English)/sizeof(English[0]);i++)
	{
		if(n==English[i].number)
		{
			printf("%s",English[i].month);
			found=1;
		}
	}
	if(!found)
	{
		printf("请检查输入的月份！\n");
	}
	return 0;
}

