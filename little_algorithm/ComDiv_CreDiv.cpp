#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//暴力枚举法
class GreatestCommonDivisor1
{
public:
	int GetGreatestCommonDivisor(int numA,int numB)
	{
		//big存储两数中的较大值，small存储两数中的较小值
		int big=numA; 
		int small=numB;
		if(numA < numB)
		{
			big=numB;
			small=numA;
		}
		int gcd=1;
		for(int i=2;i<small/2;i++)
		{
			if(numA%i == 0 && numB%i == 0)
			{
				gcd=i;
			}
		}
		return gcd;
	}
};

//辗转相除法
class GreatestCommonDivisor2
{
public:
	int GetGreatestCommonDivisor(int numA,int numB)
	{
		int big=numA; 
		int small=numB;
		if(numA < numB)
		{
			big=numB;
			small=numA;
		}
		return gcdPart(big,small);
	}
private:
	int gcdPart(int big,int small)
	{
		if(big%small == 0)
			return small;
		else
			return gcdPart(small,big%small);
	}
};
//修正版的求最大公约数
class GreatestCommonDivisor3
{
public:
	int GetGreatestCommonDivisor(int numA,int numB)
	{
		int big=numA; 
		int small=numB;
		if(numA < numB)
		{
			big=numB;
			small=numA;
		}
		return gcdPart(big,small);
	}
private:
	int gcdPart(int big,int small)
	{
		if(big%small == 0)
			return small;
		else
			return gcdPart(small,big-small);
	}
};

int main()
{
	GreatestCommonDivisor3 g;
	cout<<g.GetGreatestCommonDivisor(15,25)<<endl;     //5
	cout<<g.GetGreatestCommonDivisor(10000,10001)<<endl;   //1
	cout<<g.GetGreatestCommonDivisor(10000,1)<<endl;   //1
	system("pause");
	return 0;
}