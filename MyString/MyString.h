#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cassert>

////ֵ��������������
//class MyString
//{
//	friend ostream& operator<<(ostream& os,MyString& str);  //������������������
//	friend istream& operator>>(istream& is,MyString& str);
//public:
//	MyString(const char *str="")    //ȫȱʡ�Ĺ��캯����������ַ���������
//		:_str(new char[strlen(str)+1])
//	{
//		strcpy(_str,str);
//	}
//	MyString(const MyString& str)  //ǳ����Ҳ����ֵ����
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
//	MyString strTmp(strCopy);    //�򵥵�ֵ����
//	cout<<strTmp<<endl;
//	strTmp=str;
//	cout<<strTmp<<endl;
//	//��ʱ���ָ�붼ָ��ͬһ��ռ�,error
//};





////���
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
//	MyString(const MyString& ps)     //���
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
//	//�ִ��ķ���,������ʱ������������ͻᱻ����������
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
//	int _size;     //�ַ��ĸ���
//	int _capacity; //�ַ�������
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




////���ü������MyString
//class MyString
//{
//	friend ostream& operator<<(ostream& os,MyString& str);
//public:
//	MyString(const char *str="")
//		:_str(new char[strlen(str)+1+4])   //�����4�����������洢ָ��ÿռ��ָ�����
//	{
//		cout<<"����"<<endl;
//		_str += 4;
//		GetCount()=1;    //��ʼ�ļ�������ֵΪ1
//		strcpy(_str,str);
//	}
//	MyString(const MyString& str)
//		:_str(str._str)
//	{
//		cout<<"��������"<<endl;
//		++GetCount();
//	}
//	char& operator[](size_t index)    //дʱ�����ķ�ʽ
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
//		cout<<"����"<<endl;
//		if(--GetCount() == 0)
//		{
//			cout<<"ɾ��"<<endl;
//			Delete();
//		}
//	}
//private:
//	int& GetCount()         //��ȡ��������ֵ
//	{
//		return *(int *)(_str-4);
//	}
//	void Delete()         //ɾ���ռ䣬��ͬ�������Ŀռ�Ҳһ��ɾ��
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
		cout<<"����"<<endl;
		*_pCount=1;
		strcpy(_str,str);
	}
	MyString(const MyString& str)
		:_str(str._str)
		,_pCount(str._pCount)
	{
		cout<<"��������"<<endl;
		GetCount()++;
	}
	MyString& operator=(MyString& str)
	{
		if(this != &str)
		{
			if(--GetCount() == 0)   //���֮ǰֻ��һ��ָ��ָ��ÿռ�
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
			//�����µĴ�����ݵĿռ�ʹ�ż������Ŀռ�
			char *tmpChar=new char[strlen(_str)+1];
			int *tmpInt=new int[sizeof(int)];
			strcpy(tmpChar,_str);
			*tmpInt=*_pCount;
			Delete();     //ɾ��this��ָ���_str��__pCount
			_str=tmpChar;
			_pCount=tmpInt;
			GetCount()=1;
		}
		return _str[index];
	}
	~MyString()
	{
		cout<<"����"<<endl;
		if(--GetCount() == 0)
		{
			cout<<"ɾ��"<<endl;
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