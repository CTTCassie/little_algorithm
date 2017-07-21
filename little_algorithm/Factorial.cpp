//1、给定一个整数N，那么N的阶乘N！末尾有多少个0呢？例如：N＝10，N！＝3 628 800，N！的末尾有两个0。 

int GetZeroCount1(int N)
{
	//先计算阶乘再求0的个数，容易溢出
	if (N == 0 || N == 1)  //0!=1  1!=1，必然没有0所以返回0
		return 0;
	int count = 0;
	int Mul = 1;
	for (int i = 2; i <= N; i++)
	{
		Mul *= i;
	}
	while (Mul)
	{
		if (Mul%10 == 0)
		{
			count++;
		}
		Mul /= 10;
	}
	return count;
}


int GetZeroCount2(int N)
{
	//转化为求5的倍数的个数
	//N!=K*(10*M)，K是不能被10整除的，该题目转化为求M的大小
	//分解N!=(2*X)*(3*Y)*(5*Z)，因为2*5=10，所以又可以转化为求X和Z中较小的那个值
	//M=Min{X,Z}，因为一个数据中2的倍数出现的次数比较多，最终转化为求5的倍数的个数
	int count = 0;
	if (N == 0 || N == 1)
		return 0;
	for (int i = 1; i <= N; i++)
	{
		int j = i;
		while (j % 5 == 0)
		{
			count++;
			j /= 5;
		}
	}
	return count;
}


int GetZeroCount3(int N)
{
	int count = 0;
	if (N == 0 || N == 1)
		return 0;
	while (N)
	{
		count += N / 5;
		N /= 5;
	}
	return count;
}


const int MAX = 1000000;
int GetZeroCount4(int N)
{
	//先存储一部分数据
	int sum = 1;
	int count = 0;
	if (N == 0 || N == 1)
		return 0;
	for (int i = N; i >= 1; i--)
	{
		sum *= i;
		while (sum % 10 == 0)   //统计0出现的次数
		{
			sum /= 10;
			count++;
		}
		if (sum >= MAX)
		{
			sum %= MAX;
		}
	}
	while (sum % 10 == 0)   //消0
	{
		sum /= 10;
		count++;
	}
	return count;
}

void TestGetZeroCount()
{
	int N = 10;
	cout << GetZeroCount1(N) << endl;   //2
	cout << GetZeroCount2(N) << endl;   //2
	cout << GetZeroCount3(N) << endl;   //2
	cout << GetZeroCount4(N) << endl;   //2
}



//2、求N！的二进制表示中最低位1的位置。例如N=5，N!=5!=120，120的二进制表示为0111 1000，它的二进制中最低位1的位置是第四位。 
int GetLowest1(int N)
{
	int pos = 1;   //从倒数第一位开始
	while (N)
	{
		N >>= 1;
		pos += N;
	}
	return pos;
}