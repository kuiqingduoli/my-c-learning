#include <stdio.h>

int main()
{
	const int size=3;
	int board[size][size];
	int i,j;
	int numofX,numofO;
	int result=-1;
	printf("A为X，B为O\n");
	printf("请输入棋局情况(1为X,0为O,空位为-1)\n");
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			scanf("%d",&board[i][j]);
		}
	}
	printf("当前棋局情况为：\n");
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(board[i][j]==1)
			{
				printf("X ");
			}else if(board[i][j]==0)
			{
				printf("O ");
			}else
			{
				printf(". ");
			}
		}
		printf("\n");
	}
	for(i=0;i<size&&result==-1;i++)
	{
		numofX=0,numofO=0;
		for(j=0;j<size;j++)
		{
			if(board[i][j]==1)
			{
				numofX++;
			}else if(board[i][j]==0)
			{
				numofO++;
			}
		}
		if(numofX==size)
		{
			result=1;
		}else if(numofO==size)
		{
			result=0;
		}
	}
	if(result==-1)
	{
		for(j=0;j<size&&result==-1;j++)
		{
			numofX=0,numofO=0;
			for(i=0;i<size;i++)
			{
				if(board[i][j]==1)
				{
					numofX++;
				}else if(board[i][j]==0)
				{
					numofO++;
				}
			}
			if(numofX==size)
			{
				result=1;
			}else if(numofO==size)
			{
				result=0;
			}
		}
	}
	if(result==-1)
	{
		 numofX=0,numofO=0;
		 for(i=0;i<size;i++)
		{
			if(board[i][i]==1)
			{
				numofX++;
			}else if(board[i][i]==0)
			{
				numofO++;
			}
		}
		if(numofX==size)
		{
			result=1;
		}else if(numofO==size)
		{
			result=0;
		}
	}
	if(result==-1)
	{
		numofX=0,numofO=0;
		for(i=0;i<size;i++)
		{
			if(board[i][size-1-i]==1)
			{
				numofX++;
			}else if(board[i][size-1-i]==0)
			{
				numofO++;
			}
		}
		if(numofX==size)
		{
			result=1;
		}else if(numofO==size)
		{
			result=0;
		}
	}
	if(result==1)
	{
		printf("A获胜\n");
	}else if(result==0)
	{
		printf("B获胜\n");
	}else
	{
		printf("没有决出胜负\n");
	}
	return 0;
}
