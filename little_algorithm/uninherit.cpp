#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std; 

//class Base
//{
//protected:  //私有或者保护构造函数
//	Base(int d=0)
//		:_d(d)
//	{
//		cout<<"Base()"<<endl;
//	}
//	~Base()
//	{
//		cout<<"~Base()"<<endl;
//	}
//public:
//	//提供静态的成员方法获得当前对象
//	static Base *GetOBJ(const int& d)
//	{
//		cout<<"GetOBJ()"<<endl;
//		return new Base(d);
//	}
//	static void Delete(Base *b)  //可以声明为静态的也可以声明为非静态的
//	{
//		cout<<"Delete()"<<endl;
//		delete b;
//	}
//private:
//	int _d;
//};
//void Test()  
//{  
//	//Base tmp;  //error
//	Base *b=Base::GetOBJ(5);
//	Base::Delete(b);
//}   



//class Base
//{
//public:
//	static Base GetObject(int b)  //此处不能返回引用
//	{
//		return Base(b);
//	}
//	int GetData()
//	{
//		return _b; 
//	}
//private:
//	Base(int b=0)
//		:_b(b)
//	{}
//private:
//	int _b;
//};
//void Test()
//{
//	//Base *tmp=new Base();  //error
//	Base b = Base::GetObject(5);
//	cout<<b.GetData()<<endl;
//}



class E
{
public:
	E(int e)
		:_e(e)
	{}
	~E()
	{}
private:
	void* operator new(size_t size);//只要给出声明就行
	void operator delete(void * ptr);
private:
	int _e;
};
void test()
{
	E e(10);
	//E* p = new E(20);
}


class Base
{
public:
	Base(int b=0)
		:_b(b)
	{}
	~Base()
	{
		cout<<"~Base()"<<endl;
	}
private:
	void *operator new(size_t size);  //对new和delete进行私有处理
	void operator delete(void *ptr);
private:
	int _b;
};
void Test()
{
	Base b(10);
	//Base *tmp=new Base();  //error虽然此时构造函数是共有的，但是new这个操作符却是私有的
}

int main()
{
	//Test();
	system("pause");
	return 0;
}





//C++中编写一个不能被继承的类
//template<typename T>
//class Base
//{
//	friend T;  //定义友元，子类可以访问父类的私有成员对象
//private:
//	Base()
//	{
//		cout<<"Base()"<<endl;
//	}
//	~Base()
//	{
//		cout<<"~Base()"<<endl;
//	}
//};
////虚继承
//class Sub:virtual public Base<Sub>  
//{
//public:
//	Sub()
//	{
//		cout<<"Sub()"<<endl;
//	}
//	~Sub()
//	{
//		cout<<"~Sub()"<<endl;
//	}
//};
//class Test:public Sub
//{
//public:
//	Test()
//	{
//		cout<<"Test()"<<endl;
//	}
//	~Test()
//	{
//		cout<<"~Test()"<<endl;
//	}
//};
//int main()
//{
//	Sub s1;   //可以在栈上开辟
//	Sub *s2=new Sub; //可以在堆上开辟
//	delete s2;
//
//	Test t;
//	system("pause");
//	return 0;
//}

//class Base
//{
//public:
//	//编写静态函数来创建和释放类的实例化
//	static Base *GetSpace()
//	{
//		cout<<"GetSpace()"<<endl;
//		return new Base();
//	}
//	static void DeleteSpace(Base *del)
//	{
//		cout<<"DeleteSpace()"<<endl;
//		delete del;
//	}
//private:
//	//私有化构造和析构函数
//	Base()
//	{}
//	~Base()
//	{}
//};
//
//int main()
//{
//	//静态成员函数没有隐含this指针参数，使用类型::作用域访问符直接调用静态成员函数
//	Base *b=Base::GetSpace();
//	Base::DeleteSpace(b);
//	system("pause");
//	return 0;
//}