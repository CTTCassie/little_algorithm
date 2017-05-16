#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int FindFirstK(vector<int> data,int k,int start,int end)
	{
		if(start > end)
			return -1;
		int mid=(start+end)/2;
		if(data[mid] > k)  //在前半段找
			end=mid-1;
		else if(data[mid] == k){//k恰好在中间
			if(mid == 0 || mid > 0 && data[mid-1] != k)
				return mid;
			else
				end=mid-1;
		}
		else//data[mid] < k，后半段找
			start=mid+1;
		return FindFirstK(data,k,start,end);
	}
	int FindLastK(vector<int> data,int k,int start,int end)
	{
		int len=data.size();
		if(start > end)
			return -1;
		int mid=(start+end)/2;
		if(data[mid] > k)
			end=mid-1;
		else if(data[mid] == k){
			if(mid == len-1 || mid < len-1 && data[mid+1] != k)
				return mid;
			else
				start=mid+1;
		}
		else//data[mid] < k
			start=mid+1;
		return FindLastK(data,k,start,end);
	}
	int GetNumberOfK(vector<int> data ,int k) {
		int count=0;
		int len=data.size();
		if(len > 0 && !data.empty())
		{
			int first=FindFirstK(data,k,0,len-1);
			int last=FindLastK(data,k,0,len-1);
			if(first >= 0 && last >= 0){
				count=last-first+1;
			}
		}
		return count;
	}
};

int main()
{
	Solution so;
	vector<int> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	data.push_back(3);
	data.push_back(3);
	data.push_back(3);
	data.push_back(4);
	data.push_back(5);
	cout<<so.GetNumberOfK(data,3)<<endl;  //4
	system("pause");
	return 0;
}