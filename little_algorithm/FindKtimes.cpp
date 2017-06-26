#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cassert>
#include<map>

//����mapʵ�֣�ʱ�临�Ӷ�ΪO(N*lgN)���ռ临�Ӷ�ΪO(N)
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

//ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)
char *FindKTimes(char *str,int k)
{
	assert(str);
	char *pstr=str;
	int hash[256]={0};
	//ͳ���ַ����ֵĴ��������ù�ϣ���˼��
	while(*pstr)
	{
		//�ַ����ķ�Χ��-128~127
		hash[(unsigned char)*pstr]++;  //��ֹ����Խ��
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