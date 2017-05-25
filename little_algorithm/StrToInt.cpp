#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

enum state
{
	Valid,
	Invalid,
};
bool stat=Valid;  //全局变量，标识是空串还是"0"
class Solution {
public:
	int StrToInt(const char *str) 
	{
		stat=Invalid;
		int num=0;
		const char *digit=str;
		if(str != NULL && *str != '\0')
		{
			int flag=1;  //符号位，是否存在+,-号
			if(*digit == '+') 
				digit++;
			else if(*digit == '-')
			{
				flag=-1;
				digit++;
			}
			while(*digit != '\0')
			{
				//是否存在非法字符
				if(*digit >= '0' && *digit <= '9')
				{
					num=10*num+flag*(*digit-'0');
					//溢出的情况
					if((flag == 1) && (num > 0x7FFFFFFF) \
						|| (flag == -1) && (num < (size_t)0x80000000))
					{
						num=0;
						break;
					}
					digit++;
				}
				else
				{//非法字符,可能是字母，空格
					digit++;
				}
			}
			if(*digit == '\0')
			{
				stat=Valid;
			}
		}
		return num;
	}
};

int main()
{
	Solution so;
	//char * str="+abc12  34qwz5?6@7xyz";
	//char *str="0";  //空串stat=1或者是"0"stat=0
	char *str="-123";
	long long num=so.StrToInt(str);
	cout<<stat<<" "<<num<<endl;
	system("pause");
	return 0;
}