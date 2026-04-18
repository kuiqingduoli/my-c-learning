#include <stdio.h>
#include <string.h>

int main()
{
	/* 1.strlen:计算字符串长度(不包括结尾的'\0') */
	char word[]="hello";
	printf("1.strlen示例\n");
	printf("word=\"%s\"\n",word);//逃逸字符 \"
	printf("strlen(word)=%zu(字符串长度，不包括结尾的0)\n",strlen(word));//输出5 
	printf("sizeof(word)=%zu(数组总大小，包括结尾的0)\n",sizeof(word));//输出6 
	/* 2.strcmp:比较两个字符串
	 *返回值:0表示相等,大于0表示数组1大于数组2,小于零表示数组2大于数组1(具体值取决于编译器，通常为1或-1) 
	 */
	char word1[]="abc";
	char word2[]="Abc";
    printf("2.strcmp示例\n");
    printf("word1=\"%s\",word2=\"%s\"\n",word1,word2);
	printf("strcmp(word1,word2)=%d(比较ASCII值,'a'=97,'A'=65,所以word1>word2)\n",strcmp(word1,word2)); 
	/* 3.strcpy:复制字符串(从word4到word3)，需确保word3数组足够大，避免溢出
	 * 参数restrict表示word3和word4内存不重叠(c99) 
	 * 返回word3指针，便于调用 
	 */
	char word3[]="hello";
	char word4[]="world";
	printf("3.strcpy示例\n");
	printf("复制前：word3=\"%s\",word4=\"%s\"\n",word3,word4);
	printf("strcpy(word3,word4)=%s\n",strcpy(word3,word4)); 
	printf("复制后：word3=\"%s\"\n",word3);
	/* 4.strcat:连接字符串(将word6连接到word5末尾)，需确保word5有足够空间
	 *返回word5
	 */ 
	printf("4.strcat示例\n");
	char word5[20]="hello";//分配足够空间 
	char word6[]=" world";
	printf("连接前：word5=\"%s\",word6=\"%s\"\n",word5,word6);
	printf("strcat(word5,word6)=%s\n",strcat(word5,word6)); 
	printf("连接后：word5=\"%s\"\n",word5);
	/* 5.安全版本函数:指定操作字符数n，防止缓冲区溢出*/
	//5.1 strncpy:从word8中最多复制n个字符到word7 
	char word7[]="hello";
	char word8[]="HELLO";
	printf("5.1 strncpy示例\n");
	printf("操作前：word7=\"%s\",word8=\"%s\"\n",word7,word8);
	printf("strncpy(word7,word8,1)=%s(只复制第1个字符'H')\n",strncpy(word7,word8,1)); 
	printf("操作后：word7=\"%s\"\n",word7);
	//5.2 strncat:从word10中最多链接n个字符到word9，并自动添加结尾0 
	char word9[20]="hello";
	char word10[]=" world";
	printf("5.2 strncat示例\n");
	printf("操作前：word9=\"%s\",word10=\"%s\"\n",word9,word10);
	printf("strncat(word9,word10,2)=%s\n(只连接2个字符)",strncat(word9,word10,2)); 
	printf("操作后：word9=\"%s\"\n",word9);
	// 5.3 strncmp:比较前n个字符 
	char word11[]="abc123";
	char word12[]="abc456";
	printf("5.2 strncmp示例\n");
	printf("word11=\"%s\",word12=\"%s\"\n",word11,word12);
	printf("strncmp(word11,word12,3)=%d(前3字符相等，返回0)\n",strncmp(word11,word12,3));
	printf("strncmp(word11,word12,6)=%d(前6字符中'1'<'4'，返回负值)\n",strncmp(word11,word12,6));
	char word13[]="Hello world!";
	//查找字符还没懂，先留着待定 
	return 0;
}
