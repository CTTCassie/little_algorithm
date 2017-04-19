#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cassert>
using namespace std;

class Solution
{
public:
	void ReversePart(char *start,char *end)
	{
		assert(start);
		assert(end);
		char *left=start;
		char *right=end;
		while(left < right)
		{
			char tmp=*left;
			*left=*right;
			*right=tmp;
			left++;
			right--;
		}
	}
	char * Reverse(char *str,int len)
	{
		assert(str);
		char *start=str;
		char *end=str+len-1;
		//先反转整个句子
		//hgf ed cba
		ReversePart(start,end);
		start=end=str;
		while(*start != '\0')
		{
			if(*start == ' ')
			{
				start++;
				end++;
			}
			//再反转单词
			else if(*end == ' ' || *end == '\0')
			{
				ReversePart(start,--end);
				start=++end;
			}
			else
			{
				end++;
			}
		}
		//fgh de abc
		return str;
	}
};

int main()
{
	Solution so;
	char str[]="i am a student.";
	int len=strlen(str);
	cout<<str<<endl;
	char *ret=so.Reverse(str,len);
	cout<<ret<<endl;
	system("pause");
	return 0;
}