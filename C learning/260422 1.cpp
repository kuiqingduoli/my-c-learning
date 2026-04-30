#include <stdio.h>
/* 
复习要点总结：

1. getchar()函数：
   - 从标准输入读取一个字符
   - 返回类型是 int,可以返回字符或-1（EOF）
   - 每次调用读取一个字符
2. putchar()函数：
   - 向标准输出写入一个字符
   - 参数是 int类型，但实际写入的是对应的字符
   - 返回写入的字符，如果出错返回 EOF
3. EOF（End Of File）：
   - 是文件结束标志，值为-1
   - 键盘输入时，Windows按 Ctrl+Z然后回车，
   Linux/Mac按 Ctrl+D
   - 注意EOF不是普通字符，不会在屏幕上显示
4. 程序流程：
   - 不断读取字符并回显
   - 遇到 EOF时停止
*/
int main()
{
	int a; //使用int类型存储字符，以便正确处理EOF(通常为-1) 
	/*简单示例：读取单个字符并输出(快速测试) 
	 *a=getchar();
	 *putchar(a);
	 */
	 
	//循环读取标准输入中的字符，直到遇到 EOF
	//EOF在 Windows下由Ctrl+Z触发，在 Unix/Linux下由 Ctrl+D触发 
	while((a=getchar())!=EOF)
	{
		if(putchar(a)==EOF)//检查 putchar是否成功 
		{
			//如果 putchar 返回 EOF ，说明输出有错误 
			printf("输出错误，程序结束！\n");
			return 1; //返回1说明程序异常结束 
        }
	}
	//当 getchar遇到 EOF时，循环结束
	printf("\n正确读取到文件结束标志EOF，程序正常结束\n");
	
	return 0; //返回0表示程序正常结束 
	
/*简化版
 #include <stdio.h>

int main()
{
    int a;  // 用int存储字符，因为EOF通常是-1
    
    // 简单示例（注释掉的部分，可用于快速测试）：
    // a = getchar();  // 读取一个字符
    // putchar(a);     // 输出这个字符
    
    // 完整功能：循环读取并输出，直到遇到EOF
    printf("请输入字符（按Ctrl+Z结束）：\n");
    while ((a = getchar()) != EOF)
    {
        putchar(a);  // 输出字符
    }
    
    printf("\n已检测到EOF，程序结束。\n");
    return 0;
}
*/
}
