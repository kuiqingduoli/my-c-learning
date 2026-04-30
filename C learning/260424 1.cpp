#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//函数声明 
int mylen(char *word);
int mycmp(char *word1,char *word2);
char *mycpy(char *word5,char *word6);
char *mycat(char *word9,char *word10);
int main()
{
	//strlen 和 mylen 
	char word[]="Helloworld";
	printf("strlen(word)=%d\n",strlen(word));
	printf("mylen(word)=%d\n",mylen(word));
	//strcmp 和 mycmp 
	char word1[]="abc";
	char word2[]="abd";
	printf("strcmp(word1,word2)=%d\n",strcmp(word1,word2));
	printf("mycmp(word1,word2)=%d\n",mycmp(word1,word2));
	//strcpy 和 mycpy 
	char word3[20]="hello";
	char word4[]="Hello";
	printf("strcpy(word3,word4)=%s\n",strcpy(word3,word4));
	char word5[20]="hello";
	char word6[]="Hello";
	printf("mycpy(word5,word6)=%s\n",mycpy(word5,word6));
	//strcpy补充
	char *a=NULL;
	char b[]="hello";
	a=(char*)malloc((strlen(b)+1)*sizeof(char));
	if(a==NULL)
	{
		printf("内存分配失败\n");
		return 1;
	}
	strcpy(a,b);
	printf("a=%s\n",a);
	free(a);
	//strcat 和 mycat 
	char word7[20]="Hello";
	char word8[]="World!";
	printf("strcat(word7,word8)=%s\n",strcat(word7,word8));
	char word9[20]="Hello";
	char word10[]="World!"; 
	printf("mycat(word9,word10)=%s\n",mycat(word9,word10));
}
//mylen函数 
int mylen(char *word)
{
	int cnt=0;
	while(word[cnt]!='\0')
	{
		cnt++;
	}
	return cnt;
}
//mycmp函数 
int mycmp(char *word1,char *word2)
{
	int ret;
	int idx=0;
	while(word1[idx]==word2[idx]&&word1[idx]!='\0')
	{
		idx++;
	}
	//return word1[idx]-word2[idx];(返回相差的 ASCII码值)
	if(word1[idx]>word2[idx])
	{
		ret=1;
	}else if(word1[idx]==word2[idx])
	{
		ret=0;
	}else
	{
		ret=-1;
	}
	return ret;
	/*
	while(*word1==*word2&&*word1!='\0')
	{
		word1++;
		word2++;
	}
	//return *word1-*word2;
	if(*word1>*word2)
	{
		ret=1;
	}else if(*word1==*word2)
	{
		ret=0;
	}else
	{
		ret=-1;
	}
	return ret;
	*/
}
//mycpy函数 
char *mycpy(char *word5,char *word6)
{
	int idx=0;
	while(word6[idx]!='\0')
	{
		word5[idx]=word6[idx];
		idx++;
	}
	word5[idx]='\0';
	return word5;
}
//mycat函数 
char *mycat(char *word9,char *word10)
{
	int idx=0;
	while(word9[idx]!='\0')
	{
		idx++;
	}
	int idx2=0;
	while(word10[idx2]!='\0')
	{
		word9[idx]=word10[idx2];
		idx++;
		idx2++;
	}
	word9[idx]='\0';
	return word9;
}
