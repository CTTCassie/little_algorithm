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
				return false;     //�������Խ�����
		}
	}
	return true;   
}

void EightQueen(int *Colu,int len,int index)
{
	if(len == index)
	{
		if(IsLegal(Colu,len))   //�ж��Ƿ��ڶԽ�����
		{
			++count;
			Display(Colu,len);
		}
	}
	else
	{
		for(int i=index;i<len;++i)    //ȫ����
		{
			std::swap(Colu[index],Colu[i]);
			EightQueen(Colu,len,index+1);
			std::swap(Colu[index],Colu[i]);
		}
	}
}

void testEightQueen()
{
	//��֤���������ʺ���ͬһ��
	const int queen=8;
	int Colu[queen];
	//��֤����������ʺ�ͬ��
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

