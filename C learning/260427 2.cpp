/*第一种错误:*/
#include <stdio.h>

struct date
{
    int hour;
    int minutes;
    int seconds;
};
struct date *change(struct date *dates,int length);

int main()
{
    struct date dates[5]={{11,59,59},{12,0,0},{1,29,59},{23,59,59},{19,12,27}};
    struct date nextseconds[5];  // 声明一个数组来存储结果
    int i;
    int length=sizeof(dates)/sizeof(dates[0]);
    
    /* 核心错误1: 这里试图将一个指针赋值给整个数组，这在C语言中是不允许的 */
    /* 错误原因: 数组名是一个常量指针，不能作为左值被赋值 */
    /* 我想表达的是: 将change函数返回的指针指向的数组内容，复制到nextseconds数组中 */
    /* 但C语言中数组不能整体赋值，必须逐个元素复制 */
    /* 另外，nextseconds[5]是数组越界访问(索引0-4有效)，应该使用数组名nextseconds */
    /* 正确做法: 要么让change函数直接修改nextseconds数组，要么手动复制元素 */
    nextseconds[5]=change(&dates,length);  // 这行有多个错误，应该删除或重写
    
    for(i=0;i<length;i++)
    {
        printf("the time is %d:%d:%d\n",dates[i].hour,dates[i].minutes,dates[i].seconds);
        printf("the next second is %d:%d:%d\n",nextseconds[i].hour,nextseconds[i].minutes,nextseconds[i].seconds);
    }
    return 0;
}

struct date *change(struct date *dates,int length)
{
    int i;
    /* 问题2: 这是一个局部数组，函数返回后其内存将被释放，返回它的指针会导致悬空指针 */
    /* 虽然逻辑上我想返回一个包含结果的数组，但不能返回局部数组的指针 */
    /* 正确做法: 1. 将结果数组作为参数传入 2. 使用静态数组 3. 动态分配内存 */
    struct date nextseconds[5]; 
    
    for(i=0;i<length;i++)
    {
        if(dates[i].hour==23&&dates[i].minutes==59&&dates[i].seconds==59)
        {
            nextseconds[i].hour=0;
            nextseconds[i].minutes=0;
            nextseconds[i].seconds=0;
        }else if(dates[i].minutes==59&&dates[i].seconds==59)
        {
            nextseconds[i].hour=dates[i].hour+1;
            nextseconds[i].minutes=0;
            nextseconds[i].seconds=0;
        }else if(dates[i].seconds==59)
        {
            nextseconds[i].hour=dates[i].hour;
            nextseconds[i].minutes=dates[i].minutes+1;
            nextseconds[i].seconds=0;
        }else
        {
            nextseconds[i].hour=dates[i].hour;
            nextseconds[i].minutes=dates[i].minutes;
            nextseconds[i].seconds=dates[i].seconds+1;
        }
    }
    
    /* 问题3: 返回局部数组的指针，调用者访问这个指针将导致未定义行为 */
    return nextseconds;
}
/*第二种错误: */

struct date
{
    int hour;
    int minutes;
    int seconds;
};
struct date *change(struct date *dates,int length);

int main()
{
    struct date dates[5]={{11,59,59},{12,0,0},{1,29,59},{23,59,59},{19,12,27}};
    struct date nextseconds[5];  // 声明一个数组来存储结果
    int i;
    int length=sizeof(dates)/sizeof(dates[0]); 
    
    /* 核心错误1: 这行代码有多个问题 */
    /* 1. nextseconds[5] 是数组越界访问，因为nextseconds数组只有5个元素，索引范围是0-4 */
    /* 2. *change(dates, length) 会解引用指针，得到第一个元素(struct date类型)，然后试图将这个结构体赋值给nextseconds[5] */
    /* 3. 即使不越界，这也只赋值了一个元素，而不是将整个数组的结果复制到nextseconds中 */
    /* 4. 更重要的是，change函数直接修改了dates数组，所以dates数组已经被改写了，不再是原来的时间 */
    /* 5. 这行代码没有实现预期的功能：将计算结果存储到nextseconds数组中 */
    nextseconds[5]=*change(dates,length);  // 严重错误：数组越界访问 + 逻辑错误
    
    /* 接下来的printf中，dates数组已经被change函数修改过了，显示的是"下一秒"的时间，而不是原始时间 */
    for(i=0;i<length;i++)
    {
        // 错误：这里dates[i]显示的是已经被修改后的时间，不是原始时间
        printf("the time is %d:%d:%d\n",dates[i].hour,dates[i].minutes,dates[i].seconds);
        
        // 错误：nextseconds数组没有正确初始化，只有nextseconds[5]被赋值（越界），其他元素是垃圾值
        printf("the next second is %d:%d:%d\n",nextseconds[i].hour,nextseconds[i].minutes,nextseconds[i].seconds);
    }
    return 0;
}

struct date *change(struct date *dates,int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        /* 注意：这个函数直接修改了原始数组dates，这会带来问题：
           1. 原始数据被破坏，无法再获取原始时间
           2. 如果要计算下一秒的时间，应该保留原始数据，在另一个数组中存储结果 */
           
        if(dates[i].hour==23&&dates[i].minutes==59&&dates[i].seconds==59)
        {
            dates[i].hour=0;
            dates[i].minutes=0;
            dates[i].seconds=0;
        }else if(dates[i].minutes==59&&dates[i].seconds==59)
        {
            dates[i].hour=dates[i].hour+1;
            dates[i].minutes=0;
            dates[i].seconds=0;
        }else if(dates[i].seconds==59)
        {
            dates[i].minutes=dates[i].minutes+1;
            dates[i].seconds=0;
        }else
        {
            dates[i].seconds=dates[i].seconds+1;
        }
    }
    return dates;  // 返回指向修改后的数组的指针
}
// 修改后的正确写法示例：
#include <stdio.h>

struct date {
    int hour;
    int minutes;
    int seconds;
};

void change(struct date *dates, struct date *nextseconds, int length);

int main() {
    struct date dates[5] = {{11,59,59},{12,0,0},{1,29,59},{23,59,59},{19,12,27}};
    struct date nextseconds[5];
    int i;
    int length = sizeof(dates)/sizeof(dates[0]);
    
    // 正确：传递两个数组的指针
    change(dates, nextseconds, length);
    
    for(i = 0; i < length; i++) {
        printf("the time is %d:%d:%d\n", dates[i].hour, dates[i].minutes, dates[i].seconds);
        printf("the next second is %d:%d:%d\n", nextseconds[i].hour, nextseconds[i].minutes, nextseconds[i].seconds);
    }
    return 0;
}

void change(struct date *dates, struct date *nextseconds, int length) {
    int i;
    
    for(i = 0; i < length; i++) {
        if(dates[i].hour == 23 && dates[i].minutes == 59 && dates[i].seconds == 59) {
            nextseconds[i].hour = 0;
            nextseconds[i].minutes = 0;
            nextseconds[i].seconds = 0;
        } else if(dates[i].minutes == 59 && dates[i].seconds == 59) {
            nextseconds[i].hour = dates[i].hour + 1;
            nextseconds[i].minutes = 0;
            nextseconds[i].seconds = 0;
        } else if(dates[i].seconds == 59) {
            nextseconds[i].hour = dates[i].hour;
            nextseconds[i].minutes = dates[i].minutes + 1;
            nextseconds[i].seconds = 0;
        } else {
            nextseconds[i].hour = dates[i].hour;
            nextseconds[i].minutes = dates[i].minutes;
            nextseconds[i].seconds = dates[i].seconds + 1;
        }
    }
}
