#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	 int FindGreatestSumOfSubArray(vector<int> array)
	 {
		 if(array.empty() || array.size() <= 0)
			 return 0;
		 int cursum=0;
		 int sum=-1;
		 for(size_t i=0;i<array.size();i++)
		 {
			 if(cursum <= 0)
				 cursum = array[i];
			 else   //当前和为正数
				 cursum += array[i];
			 if(cursum > sum)
				 sum = cursum;
		 }
		 return sum;
	 }
};

int main()
{
	vector<int> array;
	Solution so;
	//-2,-8,-1,-5,-9
	//array.push_back(-2);
	//array.push_back(-8);
	//array.push_back(-1);
	//array.push_back(-5);
	//array.push_back(-9);
	//cout<<so.FindGreatestSumOfSubArray(array)<<endl; //-1
	array.push_back(6);
	array.push_back(-3);
	array.push_back(-2);
	array.push_back(7);
	array.push_back(-15);
	array.push_back(1);
	array.push_back(2);
	array.push_back(2);
	cout<<so.FindGreatestSumOfSubArray(array)<<endl; //8
	system("pause");
	return 0;
}