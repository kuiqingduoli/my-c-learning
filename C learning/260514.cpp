#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*题目：用一次遍历找到数组的最大值和最小值
void findMinMax(int arr[], int n, int* min, int* max) 
 {
    // 你的代码
 }
*考察：数组、指针参数
*/

void findMinMax(int arr[], int n, int* min, int* max);
void findMinMax2(int arr[], int n, int* min, int* max);

int main()
{
    srand(time(0));
    int n;
    printf("请输入数组大小\n");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(sizeof(int) * n);
    if(arr == NULL)    
    {
        printf("内存分配失败!\n"); 
        return 1; 
    }
    
    int i;
    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    
    printf("随机生成的数组为:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    int min, max;
    
    // 第一个版本：通过索引
    findMinMax(arr, n, &min, &max);
    printf("\n方法1: 最小值 min=%d, 最大值 max=%d\n", min, max);
    
    // 第二个版本：通过直接比较
    findMinMax2(arr, n, &min, &max);
    printf("方法2: 最小值 min=%d, 最大值 max=%d\n", min, max);
    
    free(arr);
    return 0;
}

// 方法1：通过索引
void findMinMax(int arr[], int n, int* min, int* max)
{
    int i;
    int min_index = 0;
    int max_index = 0;
    for(i = 1; i < n; i++)
    {
        if(arr[min_index] > arr[i])
        {
            min_index = i;
        }
        if(arr[max_index] < arr[i])
        {
            max_index = i;
        }
    }
    *min = arr[min_index];
    *max = arr[max_index];
}

// 方法2：通过指针直接操作
void findMinMax2(int arr[], int n, int* min, int* max)
{
    *min = arr[0];  
    *max = arr[0];  
    
    int i;
    for(i = 1; i < n; i++)
    {
        if(*min > arr[i])  // 比较min指向的值
        {
            *min = arr[i];  // 修改min指向的值
        }
        if(*max < arr[i])
        {
            *max = arr[i];
        }
    }
}
