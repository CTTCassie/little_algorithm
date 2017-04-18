#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

class Solution
{
public:
	vector<int> PrintMatrix(vector<vector<int>> matrix)
	{
		int rows1=0;
		int cols1=0;
		int rows2=matrix.size();  //4
		int cols2=matrix[0].size();//4
		assert(!matrix.empty());
		vector<int> result;
		while(rows1 < rows2 && cols1 < cols2)
		{
			//左-->右
			for(int i=cols1;i<cols2;i++)
			{
				result.push_back(matrix[rows1][i]);
			}
			rows1++;
			//上-->下
			for(int i=rows1;i<rows2;i++)
			{
				result.push_back(matrix[i][cols2-1]);
			}
			cols2--;
			//右-->左
			for(int i=cols2-1;i>=cols1;i--)
			{
				result.push_back(matrix[rows2-1][i]);
			}
			rows2--;
			//下-->上
			for(int i=rows2-1;i>=rows1;i--)
			{
				result.push_back(matrix[i][cols1]);
			}
			cols1++;
		}
		return result;
	}
	void ShowMatrix(vector<int> result)
	{
		assert(!result.empty());
		for(size_t i=0;i<result.size();i++)
		{
			cout<<result[i]<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	Solution so;
	vector<vector<int>> matrix;
	vector<int> tmp;
	//1,2,3,4
	for(int i=1;i<=4;i++)
	{
		tmp.push_back(i);
	}
	matrix.push_back(tmp);
	for(int i=1;i<=4;i++)
	{
		tmp.pop_back();
	}
	//5,6,7,8
	for(int i=5;i<=8;i++)
	{
		tmp.push_back(i);
	}
	matrix.push_back(tmp);
	for(int i=1;i<=4;i++)
	{
		tmp.pop_back();
	}
	//9,10,11,12
	for(int i=9;i<=12;i++)
	{
		tmp.push_back(i);
	}
	matrix.push_back(tmp);
	for(int i=1;i<=4;i++)
	{
		tmp.pop_back();
	}
	//13,14,15,16
	for(int i=13;i<=16;i++)
	{
		tmp.push_back(i);
	}
	matrix.push_back(tmp);

	vector<int> result=so.PrintMatrix(matrix);
	so.ShowMatrix(result);
	system("pause");
	return 0;
}