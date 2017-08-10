#include<iostream>
using namespace std;
#include<string>
#define SIZE 40

enum State
{
	EMPTY,
	ALLZERO,
	ALLSPACE,
};

int state = EMPTY;  //该全局变量是用来决定返回的0是哪一个情况

int Atoi(const string& str)
{
	int num = 0;
	if (str.empty())    //是空串
		return 0;
	char *pstr = (char *)str.c_str();
	while (isspace(*pstr))//是否存在空格
	{
		++pstr;
	}
	if (*pstr == '\0')    //全部是空格
	{
		state = ALLSPACE;
		return 0;
	}
	//确定符号位
	int flag = 1;   //正数
	if (*pstr == '-')
	{
		flag = -1;
		pstr++;
	}
	else if (*pstr == '+')
	{
		pstr++;
	}
	while (*pstr == '0')  //判断是否存在0
	{
		pstr++;
	}
	if (*pstr == '\0')    //全部是字符0
	{
		state = ALLZERO;
		return 0;
	}
	while (*pstr != '\0')
	{
		if (isdigit(*pstr))  //是数字
		{
			num = num * 10 + flag*(*pstr - '0');
			if ((flag == 1 && num >= 0x7FFFFFFF) || (flag == -1 && num <= 0x80000000) )   //判断是否溢出
			{
				num = 0;
			}
		}
		++pstr;
	}
	return num;
}
void TestAtoi()
{
	//string str = "  +00000123abc789  ";
	string str = "  -00@000123abc789  ";
	//int res = atoi(str.c_str());
	int res = Atoi(str);
	cout << res << endl;
}



void Itoa(int num, char *str)
{
	char *left = str;
	int flag = num;
	if (num < 0)   //考虑到负数的情况
		num = -num;
	while (num > 0)
	{
		*str++ = num % 10 + '0';
		num /= 10;
	}
	if (flag < 0)
	{
		*str++ = '-';
	}
	*str = '\0';
	//此时是逆序存放的，需要翻转过来
	char *right = str - 1;
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		++left;
		--right;
	}
}
void TestItoa()
{
	int num = 0;
	char buf[SIZE];
	cout << "Please input num:";
	cin >> num;
	//itoa(num,buf);
	Itoa(num,buf);
	cout << buf << endl;
}

int main()
{
	//TestAtoi();
	TestItoa();
	system("pause");
	return 0;
}