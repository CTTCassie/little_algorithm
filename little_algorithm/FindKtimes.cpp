#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cassert>
#include<map>

//利用map实现，时间复杂度为O(N*lgN)，空间复杂度为O(N)
//char *FindKTimes(char *str,int k)
//{
//	assert(str);
//	char *pstr=str;
//	map<char,int> countMap;
//	while(*pstr)
//	{
//		countMap[*pstr]++;
//		pstr++;
//	}
//	pstr=str;
//	while(*pstr)
//	{
//		if(countMap[*pstr] == 1)
//		{
//			k--;
//			if(k == 0)
//				return pstr;
//		}
//		++pstr;
//	}
//	return NULL;
//}

//时间复杂度为O(N)，空间复杂度为O(1)
char *FindKTimes(char *str,int k)
{
	assert(str);
	char *pstr=str;
	int hash[256]={0};
	//统计字符出现的次数，利用哈希表的思想
	while(*pstr)
	{
		//字符串的范围是-128~127
		hash[(unsigned char)*pstr]++;  //防止数组越界
		pstr++;
	}
	pstr=str;
	while(*pstr)
	{
		if(hash[*pstr] == 1)
		{
			k--;
			if(k == 0)
				return pstr;
		}
		++pstr;
	}
	return NULL;
}
int main()
{
	char str[]="abcdefghacefghijkmnikn";
	int k=2;
	char *res=FindKTimes(str,k);   //k=1-->b k=2-->d k=3-->j k=4-->m
	cout<<*res<<endl;
	system("pause");
	return 0;
}