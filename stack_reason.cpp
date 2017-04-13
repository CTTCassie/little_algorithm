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
		stack<int> s; //辅助栈
		int i=0,j=0;
		int size=popv.size();
		//i-->pushv,j-->popv
		while(j < size)
		{
			//如果栈为空，或者是栈的栈顶元素不是弹出序列对应的元素
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
			//栈的栈顶元素是弹出序列对应的元素,则直接出栈
			else
			{
				s.pop();
				j++;
			}
		}
		//是正确的序列
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