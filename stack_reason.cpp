#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class judge_stack
{
public:
	bool IsPopOrder(vector<int>& pushv,vector<int>& popv)
	{
		if(pushv.empty() || popv.empty() || pushv.size() != popv.size())
			return false;
		stack<int> s; //����ջ
		int i=0,j=0;
		int size=popv.size();
		//i-->pushv,j-->popv
		while(j < size)
		{
			//���ջΪ�գ�������ջ��ջ��Ԫ�ز��ǵ������ж�Ӧ��Ԫ��
			if(s.empty() || s.top() != popv[j])
			{
				if(i < size)
				{
					s.push(pushv[i++]);
				}
				else
				{
					return false;
				}
			}
			//ջ��ջ��Ԫ���ǵ������ж�Ӧ��Ԫ��,��ֱ�ӳ�ջ
			else
			{
				s.pop();
				j++;
			}
		}
		//����ȷ������
		return true;
	}
};

int main()
{
	vector<int> pushv;
	vector<int> popv;
	pushv.push_back(1);
	pushv.push_back(2);
	pushv.push_back(3);
	pushv.push_back(4);
	pushv.push_back(5);

	//popv.push_back(4);
	//popv.push_back(3);
	//popv.push_back(5);
	//popv.push_back(1);
	//popv.push_back(2);
	//judge_stack js;
	//cout<<js.IsPopOrder(pushv,popv)<<endl; //no

	popv.push_back(4);
	popv.push_back(5);
	popv.push_back(3);
	popv.push_back(2);
	popv.push_back(1);
	judge_stack js;
	cout<<js.IsPopOrder(pushv,popv)<<endl; //yes
	system("pause");
	return 0;
}