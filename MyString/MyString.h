#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cassert>

////值拷贝，存在问题
//class MyString
//{
//	friend ostream& operator<<(ostream& os,MyString& str);  //输入输出运算符的重载
//	friend istream& operator>>(istream& is,MyString& str);
//public:
//	MyString(const char *str="")    //全缺省的构造函数，解决空字符串的问题
//		:_str(new char[strlen(str)+1])
//	{
//		strcpy(_str,str);
//	}
//	MyString(const MyString& str)  //浅拷贝也就是值拷贝
//		:_str(str._str)
//	{}
//	MyString& operator=(const MyString& str)
//	{
//		if(this != &str)
//		{
//			_str=str._str;
//		}
//		return *this;
//	}
//	~MyString()
//	{
//		if(_str)
//		{
//			delete[]_str;
//		}
//	}
//private:
//	char *_str;
//};
//ostream& operator<<(ostream& os,MyString& str)
//{
//	os<<str._str;
//	return os;
//}
//istream& operator>>(istream& is,MyString& str)
//{
//	is>>str._str;
//	return is;
//}
//
//void TestMyString()
//{
//	MyString str("hello str");
//	MyString strCopy("hello DataCopy");
//	MyString strTmp(strCopy);    //简单的值拷贝
//	cout<<strTmp<<endl;
//	strTmp=str;
//	cout<<strTmp<<endl;
//	//此时多个指针都指向同一块空间,error
//};





////深拷贝
//class MyString
//{
//	friend ostream& operator<<(ostream& os,MyString& str);
//public:
//	MyString(const char *str="")
//		:_size(strlen(str))
//		,_capacity(strlen(str)+1)
//		,_str(new char[_capacity])
//	{
//		cout<<"MyString()"<<endl;
//		strcpy(_str,str);
//	}
//	MyString(const MyString& ps)     //深拷贝
//		:_size(ps._size)
//		,_capacity(strlen(ps._str)+1)
//		,_str(new char[_capacity])
//	{
//		cout<<"MyString(const MyString& ps)"<<endl;
//		strcpy(_str,ps._str);
//	}
//	//MyString& operator=(MyString& ps)
//	//{
//	//	cout<<"MyString& operator=(MyString& ps)"<<endl;
//	//	if(this != &ps)
//	//	{
//	//		delete[]_str;
//	//		_str=new char[strlen(ps._str)+1];
//	//		strcpy(_str,ps._str);
//	//	}
//	//	return *this;
//	//}
//	//现代的方法,利用临时变量出作用域就会被析构的特性
//	MyString& operator=(MyString ps)
//	{
//		cout<<"MyString& operator=(MyString& ps)"<<endl;
//		std::swap(_str,ps._str);
//		std::swap(_size,ps._size);
//		std::swap(_capacity,ps._capacity);
//		return *this;
//	}
//	~MyString()
//	{
//		cout<<"~MyString()"<<endl;
//		if(_str)
//		{
//			delete[]_str;
//			_str=NULL;
//			_size=0;
//			_capacity=0;
//		}
//	}
//private:
//	int _size;     //字符的个数
//	int _capacity; //字符的容量
//	char *_str;
//};
//
//ostream& operator<<(ostream& os,MyString& str)
//{
//	os<<str._str;
//	return os;
//}
//
//void TestMyString()
//{
//	MyString str("hello str");
//	MyString strCopy("hello DeapthCopy");
//	MyString strTmp(strCopy);
//	cout<<strTmp<<endl;
//	strTmp=str;
//	cout<<strCopy<<endl;
//};




////引用计数版的MyString
//class MyString
//{
//	friend ostream& operator<<(ostream& os,MyString& str);
//public:
//	MyString(const char *str="")
//		:_str(new char[strlen(str)+1+4])   //多分配4个整数用来存储指向该空间的指针个数
//	{
//		cout<<"构造"<<endl;
//		_str += 4;
//		GetCount()=1;    //初始的计数器的值为1
//		strcpy(_str,str);
//	}
//	MyString(const MyString& str)
//		:_str(str._str)
//	{
//		cout<<"拷贝构造"<<endl;
//		++GetCount();
//	}
//	char& operator[](size_t index)    //写时拷贝的方式
//	{
//		cout<<"operator[]"<<endl;
//		assert(index > 0 && index < strlen(_str));
//		if(GetCount() > 1)
//		{
//			--GetCount();
//			char *tmp=new char[strlen(_str)+5];
//			strcpy(tmp+4,_str);
//			Delete();
//			_str=tmp+4;
//			GetCount()=1;
//		}
//		return _str[index];
//	}
//	MyString& operator=(MyString& str)
//	{
//		cout<<"operator="<<endl;
//		if(this != &str)
//		{
//			if(--GetCount() == 0)
//			{
//				Delete();
//			}
//			++str.GetCount();
//			_str=str._str;
//		}
//		return *this;
//	}
//	~MyString()
//	{
//		cout<<"析构"<<endl;
//		if(--GetCount() == 0)
//		{
//			cout<<"删除"<<endl;
//			Delete();
//		}
//	}
//private:
//	int& GetCount()         //获取计数器的值
//	{
//		return *(int *)(_str-4);
//	}
//	void Delete()         //删除空间，连同计数器的空间也一起删除
//	{
//		delete[](_str-4);
//	}
//private:
//	char *_str;
//};
//ostream& operator<<(ostream& os,MyString& str)
//{
//	os<<str._str;
//	return os;
//}
//
//void TestMyString()
//{
//	MyString str("hello str");
//	MyString strCopy("hello ReCount");
//	MyString strTmp(str);
//	cout<<strTmp<<endl;
//	strTmp=strCopy;
//	cout<<strTmp<<endl;
//	strTmp[5]='-';
//	cout<<strTmp<<endl;
//}





class MyString
{
	friend ostream& operator<<(ostream& os,MyString str);
public:
	MyString(const char *str="")
		:_str(new char[strlen(str)+1])
		,_pCount(new int[sizeof(int)])
	{
		cout<<"构造"<<endl;
		*_pCount=1;
		strcpy(_str,str);
	}
	MyString(const MyString& str)
		:_str(str._str)
		,_pCount(str._pCount)
	{
		cout<<"拷贝构造"<<endl;
		GetCount()++;
	}
	MyString& operator=(MyString& str)
	{
		if(this != &str)
		{
			if(--GetCount() == 0)   //如果之前只有一个指针指向该空间
			{
				Delete();
			}
			str.GetCount()++;
			_str=str._str;
			_pCount=str._pCount;
		}
		return *this;
	}
	char& operator[](size_t index)
	{
		cout<<"operator[]"<<endl;
		assert(index > 0 && index < strlen(_str));
		if(GetCount() > 1)
		{
			--GetCount();
			//开辟新的存放数据的空间和存放计数器的空间
			char *tmpChar=new char[strlen(_str)+1];
			int *tmpInt=new int[sizeof(int)];
			strcpy(tmpChar,_str);
			*tmpInt=*_pCount;
			Delete();     //删除this所指向的_str和__pCount
			_str=tmpChar;
			_pCount=tmpInt;
			GetCount()=1;
		}
		return _str[index];
	}
	~MyString()
	{
		cout<<"析构"<<endl;
		if(--GetCount() == 0)
		{
			cout<<"删除"<<endl;
			Delete();
		}
	}
private:
	int& GetCount()
	{
		return *_pCount;
	}
	void Delete()
	{
		delete[]_str;
		delete[]_pCount;
	}
private:
	char *_str;
	int *_pCount;
};
ostream& operator<<(ostream& os,MyString str)
{
	os<<str._str;
	return os;
}

void TestMyString()
{
	MyString str("hello str");
	MyString strCopy("hello ReCount");
	MyString strTmp(strCopy);
	cout<<strTmp<<endl;   //hello ReCount
	strTmp=str;
	cout<<strTmp<<endl;   //hello str-->str strTmp strCopy
	strCopy=str;
	strTmp[5]='-';
	cout<<strTmp<<endl;
}