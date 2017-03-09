#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cassert>
using namespace std;

bool IsSwap(char *start,char *end)
{
	char *cur=start;
	while(cur != end)
	{
		if(*cur == *end)
			return false;
		++cur;
	}
	return true;
}

void RankPart(char *str,char *start)
{
	static int count=0;
	assert(str && start);
	if(*start == '\0')   
	{
		count++;  //统计全排列字符的个数
		cout<<count<<":"<<str<<endl;
	}
	else
	{
		char *ch=start;
		while(*ch)
		{
			if(IsSwap(start,ch))  //去重
			{
				std::swap(*ch,*start);
				RankPart(str,start+1);
				std::swap(*ch,*start);
			}
			++ch;
		}
	}
}

void Rank(char *str)
{
	if(NULL == str)
		return ;

	RankPart(str,str);
}

int main()
{
	//char str[]="abb";
	int str[]={1,2,3,4,5,6,7,8};
	Rank(str);
	system("pause");
	return 0;
}