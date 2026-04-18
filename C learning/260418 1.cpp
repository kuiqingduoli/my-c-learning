#include <stdio.h>
#include <string.h>

int main()
{
	char word[]="hello";
	printf("%lu\n",strlen(word));
	printf("%lu\n",sizeof(word));
	char word1[]="abc";
	char word2[]="Abc";
	printf("%d\n",strcmp(word1,word2));
	char word3[]="hello";
	char word4[]="world";
	printf("%s\n",strcpy(word3,word4)); 
	char word5[]="hello";
	char word6[]=" world";
	printf("%s\n",strcat(word5,word6));
	char word7[]="hello";
	char word8[]="HELLO";
	printf("%s\n",strncpy(word7,word8,1));
	char word9[]="hello";
	char word10[]=" world";
	printf("%s\n",strncat(word9,word10,2));
	char word11[]="abc123";
	char word12[]="abc456";
	printf("%d\n",strncmp(word11,word12,3));
	printf("%d\n",strncmp(word11,word12,6));
	char word13[]="Hello world!";
	//查找字符还没懂，先留着待定 
	return 0;
}
