#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;

////���ù��캯��ģ��ѭ��
//class Sum_Solution
//{
//public:
//	Sum_Solution()  //���캯������ѭ���Ĵ���
//	{
//		++_i;
//		_sum += _i;
//	}
//	static void InitData()
//	{
//		_i=0;
//		_sum=0;
//	}
//	static size_t GetSum()  //�������ս��
//	{
//		return _sum;
//	}
//private:
//	static size_t _i;
//	static size_t _sum;
//};
////ʹ�þ�̬�ı����ɱ�֤�ۼӵ�Ч��
//size_t Sum_Solution::_i=0;
//size_t Sum_Solution::_sum=0;
//void testSum_Solution()
//{
//	int n=100;
//	Sum_Solution::InitData();//���ó�ʼ������������_i����_sum����ֵ
//	Sum_Solution *tmp=new Sum_Solution[n];
//	delete[]tmp;
//	size_t ret=Sum_Solution::GetSum();
//	cout<<ret<<endl;
//}



////ʹ���麯��ģ��ݹ�ʵ��
//class A
//{
//public:
//	virtual size_t GetSum(size_t n)  //�ݹ����������
//	{
//		return 0;
//	}
//};
//A *arr[2];
//class B:public A
//{
//public:
//	virtual size_t GetSum(size_t n)  //�ݹ��ʵ��
//	{
//		return arr[!!n]->GetSum(n-1)+n;
//	}
//};
//void testSolution()
//{
//	//n==0,����A::GetSum(),��n != 0��ʱ�����B::GetSum()
//	int n=100;
//	A a;
//	B b;
//	arr[0]=&a;
//	arr[1]=&b;
//	size_t sum=arr[1]->GetSum(n); 
//	cout<<sum<<endl;
//}




////���ú���ָ����ʵ��
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
	//��nΪ0��ʱ��ִֻ��ǰ������������Ϊfalse
	//��n����0��ʱ�����ִ�е������������ʵ�ֵݹ���㣬
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