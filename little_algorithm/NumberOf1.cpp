#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
using namespace std;

class Solution {
private:
	int PowerBase(int num)
	{
		int result=1;
		for(int i=0;i<num;i++)
		{
			result *= 10;
		}
		return result;
	}
	int NumberOf1(const char *str)
	{
		//当前获取到的数据不是0~9的数字，或者已经到该字符串结尾
		if(!str || *str < '0' || *str > '9' || *str == '\0'){
			return 0;
		}
		int tmp=*str-'0';   //tmp保存第一个数据
		int size=strlen(str);
		if(tmp == 0 && size == 1){  //只有一个数据0
			return 0;
		}
		if(tmp > 0 && size == 1){   //只有一个数据是正数
			return 1;
		}
		int fdigit=0;
		if(tmp > 1){
			fdigit=PowerBase(size-1);
		}
		else{
			fdigit=atoi(str+1)+1;
		}
		int odigit=tmp*(size-1)*PowerBase(size-2);
		int curgigit=NumberOf1(str+1);
		return fdigit+odigit+curgigit;
	}
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if(n <= 0){  //输入错误数据
			return 0;
		}
		//将数字转化为字符串处理
		char str[50];
		sprintf(str,"%d",n);
		return NumberOf1(str);
	}
};

int main()
{
	Solution so;
	int n=0;
	cin>>n;
	cout<<so.NumberOf1Between1AndN_Solution(n)<<endl;
	//13-->6
	//21345-->18821
	system("pause");
	return 0;
}