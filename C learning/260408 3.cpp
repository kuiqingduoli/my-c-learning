#include <stdio.h>

int main()
{
	int x,i;
	printf("«Î ‰»Î”≤±“ ˝∂Ó\n");
	scanf("%d",&x);
	const char *name[]={"penny","nickel","dime","quarter","half_dollar"};
	int number[]={1,5,10,25,50};
	struct
	{
		int number;
		const char *name;
	}coins[]=
	{
		{1,"penny"},
		{5,"nickel"},
		{10,"dime"},
		{25,"quarter"},
		{50,"half_dollar"}
	};
	int length=sizeof(coins)/sizeof(coins[0]);
	int found=0;
	for(i=0;i<length;i++)
	{
		if(coins[i].number==x)
		{
			printf("%s",coins[i].name);
			found=1;
			break;
		}
	}
	if(!found)
	{
		printf("Not found!\n");
	}
}
