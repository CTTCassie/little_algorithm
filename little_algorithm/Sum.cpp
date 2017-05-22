#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;

////利用构造函数模拟循环
//class Sum_Solution
//{
//public:
//	Sum_Solution()  //构造函数控制循环的次数
//	{
//		++_i;
//		_sum += _i;
//	}
//	static void InitData()
//	{
//		_i=0;
//		_sum=0;
//	}
//	static size_t GetSum()  //返回最终结果
//	{
//		return _sum;
//	}
//private:
//	static size_t _i;
//	static size_t _sum;
//};
////使用静态的变量可保证累加的效果
//size_t Sum_Solution::_i=0;
//size_t Sum_Solution::_sum=0;
//void testSum_Solution()
//{
//	int n=100;
//	Sum_Solution::InitData();//调用初始化函数给变量_i，和_sum赋初值
//	Sum_Solution *tmp=new Sum_Solution[n];
//	delete[]tmp;
//	size_t ret=Sum_Solution::GetSum();
//	cout<<ret<<endl;
//}



////使用虚函数模拟递归实现
//class A
//{
//public:
//	virtual size_t GetSum(size_t n)  //递归结束的条件
//	{
//		return 0;
//	}
//};
//A *arr[2];
//class B:public A
//{
//public:
//	virtual size_t GetSum(size_t n)  //递归的实现
//	{
//		return arr[!!n]->GetSum(n-1)+n;
//	}
//};
//void testSolution()
//{
//	//n==0,调用A::GetSum(),当n != 0的时候调用B::GetSum()
//	int n=100;
//	A a;
//	B b;
//	arr[0]=&a;
//	arr[1]=&b;
//	size_t sum=arr[1]->GetSum(n); 
//	cout<<sum<<endl;
//}




////利用函数指针来实现
//typedef size_t (*GetSum)(size_t);
//size_t Finish(size_t n)
//{
//	return 0;
//}
//size_t Sum_Solution(size_t n)
//{
//	static GetSum arr[2]={Finish,Sum_Solution};
//	return n+arr[!!n](n-1);
//}

size_t Sum_Solution(size_t n)
{
	//当n为0的时候只执行前面的条件，结果为false
	//当n大于0的时候可以执行到后面的条件，实现递归计算，
	int sum=n;
	bool ret=(n > 0) && ((sum += Sum_Solution(n-1)) > 0);
	return sum;
}

int main()
{
	//testSum_Solution();
	//testSolution();
	int sum=Sum_Solution(100);
	cout<<sum<<endl;
	system("pause");
	return 0;
}