#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<stack>
#include<vector>
#include<cassert>
using namespace std;

//template<class T>
//class DoubleMaxStack
//{
//public:
//	void Push(const T& data)
//	{
//		//������ջΪ�ջ�����data�ȸ���ջջ�������ݴ�������ջ��������
//		if(_ptr1.empty() || data >= _ptr2.top())
//		{
//			_ptr1.push(data);
//			_ptr2.push(data);
//		}
//		else
//		{
//			_ptr1.push(data);
//		}
//	}
//	void Pop()
//	{
//		assert(!_ptr1.empty());
//		if(_ptr1.top() == _ptr2.top())
//		{
//			_ptr1.pop();
//			_ptr2.pop();
//		}
//		_ptr1.pop();
//	}
//	const T& Max()
//	{
//		//���ָ���ջջ����Ԫ��һֱ�����ֵ
//		return _ptr2.top();
//	}
//protected:
//	stack<T> _ptr1;   //����ջ
//	stack<T> _ptr2;   //����ջ
//};
//
//int main()
//{
//	DoubleMaxStack<int> s;
//	s.Push(5);
//	s.Push(2);
//	s.Push(10);
//	s.Push(1);
//	cout<<s.Max()<<endl;
//	s.Pop();
//	s.Pop();
//	cout<<s.Max()<<endl;
//	system("pause");
//	return 0;
//}









#include<iostream>
using namespace std;
#include<cassert>
//strstr���ص��ǵ�һ���Ӵ����ֵ�λ��
char *my_strstr(const char *str,const char *substr)
{
	char *ptr=NULL;
	assert(str);
	assert(substr);
	char *pstr=(char *)str;
	char *psubstr=(char *)substr;
	while(*pstr != '\0')
	{
		ptr=pstr;    //��¼Ҫ�����Ӵ���λ��
		//ƥ��Ļ�������Ƚ�
		while(*pstr != '\0' && *psubstr != '\0' && *pstr == *psubstr)
		{
			pstr++;
			psubstr++;
		}
		if(*psubstr == '\0')
			return (char *)ptr;
		//��ƥ����ԭ�����������ң��Ӵ�����ԭλ��
		pstr=ptr+1;
		psubstr=(char *)substr;
	}
	return NULL;
}

int main()
{
	char *str="abcdfghcdeijkcde";
	char *substr="cde";
	char *ret=my_strstr(str,substr);
	printf("%s\n",ret);  //cdeijk
	system("pause");
	return 0;
}