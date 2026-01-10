#include <stdio.h>

int main()
{
	double cm = 0,m = 0,total_foot = 0;
	int inch = 0,foot = 0;
	
	printf("请输入您的身高(厘米)\n");
	scanf("%lf",&cm);

	m = cm/100.0;
	total_foot = m / 0.3048;
	foot = (int)total_foot;
	inch = (int)((total_foot - foot) * 12 + 0.5);
	
	printf("您的身高为%d英尺%d英寸\n",foot,inch);
	
	return 0;
}
