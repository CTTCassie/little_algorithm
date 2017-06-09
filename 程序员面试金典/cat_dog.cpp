#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class CatDogAsylum {
public:
	vector<int> asylum(vector<vector<int>> ope) {
		// write code here
		queue<int> cat;
		queue<int> dog;
		vector<int> tmp;
		int index=0;   //指定先来后到的顺序
		int len=ope.size();
		for(int i=0;i<len;i++)
		{
			switch(ope[i][0])
			{
			case 1:    //有动物进入
				if(ope[i][1] >= 0){   //正数代表狗
					dog.push(index++);
					dog.push(ope[i][1]);
				}
				else{   //负数代表猫
					cat.push(index++);
					cat.push(ope[i][1]);
				}
				break;
			case 2:    //有人收养动物
				if(ope[i][1] == 0){   //采用第一种收养方式
					 //比较两种动物的进入时间
					int time=0;
					if(!cat.empty() && !dog.empty())  //猫狗队列都不为空
						time=dog.front() > cat.front() ? -1 : 1;
					else if(!cat.empty() && dog.empty())//狗队列为空猫队列不为空
						time=-1;
					else if(cat.empty() && !dog.empty())//猫队列为空狗队列不为空
						time=1;
					if(time == -1){  //猫先来先收养猫
						cat.pop();
						tmp.push_back(cat.front());
						cat.pop();
					}
					if(time == 1){   //狗先来先收养狗
						dog.pop();
						tmp.push_back(dog.front());
						dog.pop();
					}
				}
				else if(ope[i][1] == 1){  //指定收养狗
					if(!dog.empty()){
						dog.pop();
						tmp.push_back(dog.front());
						dog.pop();
					}
				}
				else{  //指定收养猫
					if(!cat.empty()){
						cat.pop();
						tmp.push_back(cat.front());
						cat.pop();
					}
				}
				break;
			}
		}
		return tmp;
	}
};

int main()
{
	CatDogAsylum cat_dog;
	vector<int> res;
	vector<vector<int>> ope;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	ope.push_back(v);

	v.pop_back();
	v.pop_back();
	v.push_back(1);
	v.push_back(-1);
	ope.push_back(v);

	v.pop_back();
	v.pop_back();
	v.push_back(2);
	v.push_back(0);
	ope.push_back(v);

	v.pop_back();
	v.pop_back();
	v.push_back(2);
	v.push_back(-1);
	ope.push_back(v);
	res=cat_dog.asylum(ope);
	for(size_t i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}