#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void replaceSpace(char *str)
//{
//	int count=0;
//	int newsize=0;
//	int length=strlen(str);
//	int oldsize=length;
//	char *tmp=str;
//	统计空格的个数
//	while(*tmp != '\0')
//	{
//		if(*tmp == ' ')
//		{
//			count++;
//		}
//		tmp++;
//	}
//	newsize=oldsize+2*count;
//	while(oldsize < newsize)
//	{
//		如果是空格则直接替换
//		if(str[oldsize] != ' ')
//		{
//			str[newsize--]=str[oldsize--];
//		}
//		是空格则使用%20替换
//		else
//		{
//			str[newsize--]='0';
//			str[newsize--]='2';
//			str[newsize--]='%';
//			oldsize--;
//		}
//	}
//}

char * replaceSpace(char *str,int length) {
	int count=0;
	int newsize=0;
	char *tmp=str;
	char *newstr=NULL;
	//统计空格的个数
	while(*tmp != '\0')
	{
		if(*tmp == ' ')
		{
			count++;
		}
		tmp++;
	}
	//计算新开辟的空间大小
	newsize=length+2*count;   
    newstr=(char *)malloc(newsize*sizeof(char));
	tmp=newstr;
	while(*str != '\0')
	{
		//是空格则替换%20
		if(*str == ' ')
		{
			*newstr++='%';
			*newstr++='2';
			*newstr++='0';
			str++;
		}
		else{
			*newstr=*str;
			newstr++;
			str++;
		}
	}
	*newstr='\0';
	return tmp;
}

int main()
{
	//char str[20]="i love you!";
	//printf("%s\n",str);
	//replaceSpace(str);
	//printf("%s\n",str);

	char str[20]="i love you!";
	char *ret=NULL;
	int len=strlen(str);
	printf("%s\n",str);
	ret=replaceSpace(str,len);
	printf("%s\n",ret);
	system("pause");
	return 0;
}