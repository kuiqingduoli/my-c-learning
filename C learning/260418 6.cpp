#include <stdio.h>

int sum(const int arr[],int length);
int main()
{
	int i=10,j=20; 
	/* 1.指针是const(指针本身不能变)*/
	int *const q=&i;//q是const,初始化后不能再指向其他变量 
	*q=26;//OK：可以通过指针修改变量 
	//q=&j; //error:q是const，不能重新赋值 
	
	/* 2.所指是const(不能通过指针修改变量)*/
	int const *p=&i;//*p是const 
	//或者const int *p=&b;
	//*p=26  //error:不能通过*p修改变量 
	i=26;//OK:可以直接修改i 
	p=&j;//OK:可以改变指针指向
	
	/* 3.const数组*/
	const int arr[]={1,2,3,4,5,6};
	//arr[0]=10; //error:数组元素是常量 
	//所以const数组必须在初始化时赋值
	
	/* 4.保护数组值(函数中使用const参数)*/
	int length=sizeof(arr)/sizeof(arr[0]);
	int result=sum(arr,length);
	printf("%d",result);
	return 0;
}
int sum(const int arr[],int length)
	{
		int total=0;
		int i; 
		for(i=0;i<length;i++)
		{
			total+=arr[i];
			//如果尝试修改arr[i]会编译错误
			//arr[i]=0; //error! 
		}
		return total;
	}
