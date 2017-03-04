#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

int count=0;

void Display(int *Colu,int len)
{
	cout<<count<<":"<<endl;
	for(int i=0;i<len;++i)
	{
		cout<<Colu[i]<<" ";
	}
	cout<<endl;
}

bool IsLegal(int *Colu,int len)
{
	int i=0,j=0;
	for(i=0;i<len;++i)
	{
		for(j=i+1;j<len;++j)
		{
			if((i-j == Colu[i]-Colu[j]) || (j-i == Colu[i]-Colu[j]))
				return false;     //在正副对角线上
		}
	}
	return true;   
}

void EightQueen(int *Colu,int len,int index)
{
	if(len == index)
	{
		if(IsLegal(Colu,len))   //判断是否在对角线上
		{
			++count;
			Display(Colu,len);
		}
	}
	else
	{
		for(int i=index;i<len;++i)    //全排列
		{
			std::swap(Colu[index],Colu[i]);
			EightQueen(Colu,len,index+1);
			std::swap(Colu[index],Colu[i]);
		}
	}
}

void testEightQueen()
{
	//保证任意两个皇后不在同一行
	const int queen=8;
	int Colu[queen];
	//保证任意的两个皇后不同列
	for(int i=0;i<queen;++i)
	{
		Colu[i]=i;
	}
	EightQueen(Colu,queen,0);
}

int main()
{
	testEightQueen();
	system("pause");
	return 0;
}

