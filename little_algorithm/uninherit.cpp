#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std; 

//class Base
//{
//protected:  //˽�л��߱������캯��
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
//	//�ṩ��̬�ĳ�Ա������õ�ǰ����
//	static Base *GetOBJ(const int& d)
//	{
//		cout<<"GetOBJ()"<<endl;
//		return new Base(d);
//	}
//	static void Delete(Base *b)  //��������Ϊ��̬��Ҳ��������Ϊ�Ǿ�̬��
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
//	static Base GetObject(int b)  //�˴����ܷ�������
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
	void* operator new(size_t size);//ֻҪ������������
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
	void *operator new(size_t size);  //��new��delete����˽�д���
	void operator delete(void *ptr);
private:
	int _b;
};
void Test()
{
	Base b(10);
	//Base *tmp=new Base();  //error��Ȼ��ʱ���캯���ǹ��еģ�����new���������ȴ��˽�е�
}

int main()
{
	//Test();
	system("pause");
	return 0;
}





//C++�б�дһ�����ܱ��̳е���
//template<typename T>
//class Base
//{
//	friend T;  //������Ԫ��������Է��ʸ����˽�г�Ա����
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
////��̳�
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
//	Sub s1;   //������ջ�Ͽ���
//	Sub *s2=new Sub; //�����ڶ��Ͽ���
//	delete s2;
//
//	Test t;
//	system("pause");
//	return 0;
//}

//class Base
//{
//public:
//	//��д��̬�������������ͷ����ʵ����
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
//	//˽�л��������������
//	Base()
//	{}
//	~Base()
//	{}
//};
//
//int main()
//{
//	//��̬��Ա����û������thisָ�������ʹ������::��������ʷ�ֱ�ӵ��þ�̬��Ա����
//	Base *b=Base::GetSpace();
//	Base::DeleteSpace(b);
//	system("pause");
//	return 0;
//}