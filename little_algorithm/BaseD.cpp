#include<iostream>
using namespace std;

////C++中的多态
//class B
//{
//public:
//	B(const int& a=0)
//		:_a(a)
//	{}
//	virtual void Print()
//	{
//		cout<<"B:"<<_a<<endl;
//	}
//protected:
//	int _a;
//};
//class D:public B
//{
//public:
//	D(const int& b=0)
//		:_b(b)
//	{}
//	virtual void Print()
//	{
//		cout<<"D:"<<_b<<endl;
//	}
//protected:
//	int _b;
//};
//void func(B *ptr)
//{
//	ptr->Print();
//}
//void TestCPP()
//{
//	B b(1);
//	D d(2);
//	B *ptr=&b;
//	ptr->Print();  //1
//	ptr=&d;
//	ptr->Print();  //2
//	func(&b);  //1
//	func(&d);  //2
//}


//C语言模拟实现继承和多态

typedef void (*FUNC)();    //使用函数指针来模拟实现

struct B   //父类
{
	FUNC _func;
	int _a;
};
struct D  //子类
{
	B _ca;   
	int _b;
};
void B_Func()   //父类的成员函数
{
	printf("B:_func()\n");
}
void D_Func()   //子类的成员函数
{
	printf("D:_func()\n");
}
//父类的指针可以指向父类或者子类的对象
void func(B *ptr) //公有的接口
{
	ptr->_func();
}
void TestC()
{
	B b;
	D d;
	//对父类和子类的成员函数进行初始化
	b._func=B_Func;
	d._ca._func=D_Func;
	 //父类的对象调用父类的成员函数
	b._func();
	//子类的对象要调用自己的成员函数，需要先找到自己继承过来的父类的函数指针再调用父类的成员函数
	d._ca._func();


	B *ptr=&b;   //一个父类的指针指向父类的对象
	ptr->_func();
	ptr=(B *)&d; //父类的指针也可以指向子类的对象，在C语言中需要强制类型转换
	ptr->_func();
}
int main()
{
	//TestCPP();
	TestC();
	system("pause");
	return 0;
}