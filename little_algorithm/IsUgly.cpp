#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class Solution {
//public:
//	bool IsUgly(int num)
//	{
//		while(num%2 == 0)
//			num /= 2;
//		while(num%3 == 0)
//			num /= 3;
//		while(num%5 == 0)
//			num /= 5;
//		if(num == 1) //是丑数
//			return true;
//		else         //不是丑数
//			return false;
//	}
//	int GetUglyNumber_Solution(int index) {
//		if(index < 0){
//			return 0;
//		}
//		int num=0;
//		int ugly=0;
//		while(ugly < index)
//		{
//			++num;
//			if(IsUgly(num)){
//				ugly++;
//			}
//		}
//		return num;
//	}
//};

class Solution {
public:
	int FindMin(int num1,int num2,int num3)//查找三个数中的最小值
	{
		if(num1 < num2)
		{
			if(num1 < num3)
				return num1;
			else
				return num3;
		}
		else//num1 >= num2
		{
			if(num2 < num3)
				return num2;
			else
				return num3;
		}
	}
	int GetUglyNumber_Solution(int index)
	{
		if(index <= 0)
			return 0;
		int *numbers=new int[index];
		numbers[0]=1;  //1是第一个丑数
		int next=1;    //从第二个位置开始查找
		int *tags2=numbers;
		int *tags3=numbers;
		int *tags5=numbers;
		while(next < index)
		{
			int min=FindMin(*tags2*2,*tags3*3,*tags5*5);
			numbers[next]=min;
			while(*tags2*2 <= numbers[next])
			{
				++tags2;
			}
			while(*tags3*3 <= numbers[next])
			{
				++tags3;
			}
			while(*tags5*5 <= numbers[next])
			{
				++tags5;
			}
			++next;
		}
		int ugly=numbers[next-1];
		delete[]numbers;
		return ugly;
	}
};

int main()
{
	Solution so;
	int uglynum=0;
	cin>>uglynum;
	int ret=so.GetUglyNumber_Solution(uglynum);
	cout<<ret<<endl;
	system("pause");
	return 0;
}