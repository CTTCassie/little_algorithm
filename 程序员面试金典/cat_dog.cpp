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
		int index=0;   //ָ�������󵽵�˳��
		int len=ope.size();
		for(int i=0;i<len;i++)
		{
			switch(ope[i][0])
			{
			case 1:    //�ж������
				if(ope[i][1] >= 0){   //��������
					dog.push(index++);
					dog.push(ope[i][1]);
				}
				else{   //��������è
					cat.push(index++);
					cat.push(ope[i][1]);
				}
				break;
			case 2:    //������������
				if(ope[i][1] == 0){   //���õ�һ��������ʽ
					 //�Ƚ����ֶ���Ľ���ʱ��
					int time=0;
					if(!cat.empty() && !dog.empty())  //è�����ж���Ϊ��
						time=dog.front() > cat.front() ? -1 : 1;
					else if(!cat.empty() && dog.empty())//������Ϊ��è���в�Ϊ��
						time=-1;
					else if(cat.empty() && !dog.empty())//è����Ϊ�չ����в�Ϊ��
						time=1;
					if(time == -1){  //è����������è
						cat.pop();
						tmp.push_back(cat.front());
						cat.pop();
					}
					if(time == 1){   //��������������
						dog.pop();
						tmp.push_back(dog.front());
						dog.pop();
					}
				}
				else if(ope[i][1] == 1){  //ָ��������
					if(!dog.empty()){
						dog.pop();
						tmp.push_back(dog.front());
						dog.pop();
					}
				}
				else{  //ָ������è
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