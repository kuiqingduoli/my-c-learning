#include <stdio.h>
#include <stdlib.h>

struct time
{
    int hour;
    int minutes;
    int seconds;
};
// 函数原型声明
struct time *change(struct time *now, int length);

int main()
{
    // 定义并初始化原始时间数组
    struct time now[5]={{11,59,59},{12,0,0},{1,29,59},{23,59,59},{19,12,27}};
    int length=sizeof(now)/sizeof(now[0]);
    
    // 调用change函数获取下一秒的时间数组
    // change函数会动态分配内存，返回指向这个内存的指针
    struct time *nextsecond=change(now,length);
    
    // 检查内存分配是否成功
    if(nextsecond == NULL) {
        printf("内存分配失败，程序退出！\n");
        return 1;  // 返回非0值表示程序异常结束
    }
    
    int i;
    for(i=0;i<length;i++)
    {
        // 打印原始时间
        printf("now is %d:%d:%d\n",now[i].hour,now[i].minutes,now[i].seconds);
        // 打印下一秒时间
        printf("the next second is %d:%d:%d\n",nextsecond[i].hour,nextsecond[i].minutes,nextsecond[i].seconds);
    }
    
    // 重要：释放动态分配的内存
    // 注意：这里释放的是nextsecond，不是getnextsecond
    // 原因：getnextsecond是change函数中的局部变量，在main函数中不可见
    // nextsecond是main函数中接收change返回值的变量，指向动态分配的内存
    free(nextsecond);
    
    return 0;
}

struct time *change(struct time *now,int length)
{
    // 在堆上动态分配内存，用于存储结果
    // 注意：getnextsecond是局部变量，但指向的内存是在堆上分配的
    // 堆内存不会随着函数结束而自动释放，需要手动管理
    struct time *getnextsecond=(struct time*)malloc(length*sizeof(struct time));
    
    // 检查内存分配是否成功
    if(getnextsecond == NULL) {
        printf("change函数中内存分配失败！\n");
        return NULL;  // 返回NULL表示失败
    }
    
    int i;
    for(i=0;i<length;i++)
    {
        // 计算每个时间点下一秒的值
        if(now[i].hour==23&&now[i].minutes==59&&now[i].seconds==59)
        {
            getnextsecond[i].hour=0;
            getnextsecond[i].minutes=0;
            getnextsecond[i].seconds=0;
        }else if(now[i].minutes==59&&now[i].seconds==59)
        {
            getnextsecond[i].hour=now[i].hour+1;
            getnextsecond[i].minutes=0;
            getnextsecond[i].seconds=0;
        }else if(now[i].seconds==59)
        {
            getnextsecond[i].hour=now[i].hour;
            getnextsecond[i].minutes=now[i].minutes+1;
            getnextsecond[i].seconds=0;
        }else
        {
            getnextsecond[i].hour=now[i].hour;
            getnextsecond[i].minutes=now[i].minutes;
            getnextsecond[i].seconds=now[i].seconds+1;
        }
    }
    
    // 返回动态分配的内存地址
    // 注意：getnextsecond这个变量会在函数结束时被销毁
    // 但它指向的内存在堆上，不会被自动释放
    return getnextsecond;
}
