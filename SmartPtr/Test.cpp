#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#define ADD(a,b) (a+b)  

#define SWAP(a,b){  \
	int tmp=a;      \
    a=b;            \
	b=tmp;         \
}while(false);

class MyString
{
	friend ostream& operator<<(ostream& os,const MyString& s);
public:
	MyString(const char *s="")
		:_str(new char[strlen(s)+1])
	{
		strcpy(_str,s);
	}
	//�ִ���д����������ʱ������������ͻᱻ���ٵ�����
	MyString(const MyString& s)   //s2(s1)
		:_str(NULL)
	{
		MyString tmp(s._str);
		swap(_str,tmp._str);
	}
	MyString& operator=(MyString s)   //s3=s1;
	{
		if(this != &s)
		{
			swap(_str,s._str);
		}
		return *this;
	}
	//��ͳд��

	//MyString(const MyString& s)   //s2(s1)
	//	:_str(new char[strlen(s._str)+1])
	//{
	//	strcpy(_str,s._str);
	//}
	//MyString& operator=(const MyString& s)  //s3=s1
	//{
	//	if(this != &s)
	//	{
	//		delete[]_str;
	//		_str=new char[strlen(s._str)+1];
	//		strcpy(_str,s._str);
	//	}
	//	return *this;
	//}
	~MyString()
	{
		delete[]_str;
	}
protected:
	char *_str;
};
ostream& operator<<(ostream& os,const MyString& s)
{
	cout<<s._str;
	return os;
}
void TestMyString()
{
	MyString s1("string");
	cout<<s1<<endl;
	MyString s2(s1);
	cout<<s2<<endl;
	MyString s3;
	s3=s1;
	cout<<s3<<endl;
}


//����ֵ������
#include<string>
template<class T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr=0)
		:_ptr(ptr)
	{}
	~ScopedPtr()
	{
		delete _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	ScopedPtr(const ScopedPtr<T>&);
	ScopedPtr& operator=(const ScopedPtr<T>&);
protected:
	T *_ptr;
};
void TestScopedPtr()
{
	ScopedPtr<int> sp1(new int(10));
	cout<<*sp1<<endl;
	//ScopedPtr<int> sp2(sp1);     //error
	ScopedPtr<pair<string,int>> sp2(new pair<string,int>("ScopedPtr",1));
	cout<<sp2->first<<endl;
	cout<<sp2->second<<endl;
	(sp2.operator->())->first="Change";
	cout<<(*sp2).first<<endl;
}


//Ȩ��ת��
template<class T>
class AutoPtr
{
public:
	AutoPtr(T *ptr=0)
		:_ptr(ptr)
	{}
	~AutoPtr()
	{
		delete _ptr;
	}
	AutoPtr(AutoPtr<T>& ap)   //ap2(ap1)
	{
		_ptr=ap._ptr;
		ap._ptr=0;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap)  //ap2=ap1
	{
		if(this != &ap)
		{
			delete _ptr;
			_ptr=ap._ptr;
			ap._ptr=0;
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T *operator->()
	{
		return _ptr;
	}
protected:
	T *_ptr;
};
void TestAutoPtr()
{
	AutoPtr<int> ap1(new int(10));
	cout<<*ap1<<endl;
	AutoPtr<int> ap2(ap1);
	cout<<*ap2<<endl;
	AutoPtr<int> ap3(new int(20));
	ap3=ap2;
	cout<<*ap3<<endl;
}


//���ü���
template<class T>
class SharedPtr
{
public:
	SharedPtr(T *ptr=0)
		:_ptr(ptr)
		,_pcount(new int(1))
	{}
	~SharedPtr()
	{
		cout<<"����"<<endl;
		if(--GetCount() == 0)
		{
			cout<<"ɾ��"<<endl;
			Destroy();
		}
	}
	SharedPtr(const SharedPtr<T>& sp)   //sp2(sp1)
	{
		_ptr=sp._ptr;
		_pcount=sp._pcount;
		//ʹ��thisָ��ָ��ÿռ䣬�������ü�����1
		++GetCount();
	}
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)  //sp3=sp2
	{
		if(this != &sp)    //�����Լ����Լ���ֵ
		{
			//thisָ������ü���-1.��������һ��ָ��ÿռ��ֻ��ָ�������ٸÿռ�
			if(--GetCount() == 0)
			{
				Destroy();
			}
			//���¸�thisָ�븳���µ�����ָ��
			_ptr=sp._ptr;
			_pcount=sp._pcount;
			++GetCount();
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T *operator->()
	{
		return _ptr;
	}
private:
	void Destroy()    //���ٸ�����ָ��
	{
		delete _ptr;
		_ptr=0;
		delete _pcount;
		_pcount=0;
	}
	int& GetCount()   //��ȡ���ü�����ֵ
	{
		return *_pcount;
	}
protected:
	T *_ptr;
	int *_pcount;
};

void TestSharedPtr()
{
	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(sp1);
	cout<<*sp1<<endl;
	cout<<*sp2<<endl;
	SharedPtr<int> sp3(new int(20));
	cout<<*sp3<<endl;
	sp3=sp2;
	cout<<*sp3<<endl;
}



//shared_ptr��ѭ�����õ�����
#include<boost/shared_ptr.hpp>
#include<boost/weak_ptr.hpp>
struct Node
{
	Node(const int& data=0)
		:_data(data)
	{}
	~Node()
	{
		cout<<"~Node()"<<endl;
	}
	int _data;
	boost::weak_ptr<Node> _next;
	boost::weak_ptr<Node> _prev;
};
void Testshared_ptr()
{
	boost::shared_ptr<Node> n1(new Node(10));
	boost::shared_ptr<Node> n2(new Node(20));
	cout<<n1.use_count()<<endl;   //1
	cout<<n2.use_count()<<endl;   //1
	n1->_next=n2;
	n2->_prev=n1;
	cout<<n1.use_count()<<endl;    //2
	cout<<n2.use_count()<<endl;    //2
}

int main()
{
	//TestMyString();
	//TestScopedPtr();
	//TestAutoPtr();
	//TestSharedPtr();
	Testshared_ptr();
	//int a=1,b=2;
	//cout<<ADD(a,b)<<endl;
	//cout<<a<<" "<<b<<endl;
	//SWAP(a,b);
	//cout<<a<<" "<<b<<endl;
	////SWAP(a,b);   
	//if(1)
	//	SWAP(a,b);
	//cout<<a<<" "<<b<<endl;
	system("pause");
	return 0;
}