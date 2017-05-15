#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	long InversePairsPart(vector<int>& data, int *tmp,long start,long end)
//	{
//		if(start == end){
//			tmp[start]=data[start];
//			return 0;
//		}
//		long mid=(end-start)/2;
//		long left=InversePairsPart(data,tmp,start,start+mid);
//		long right=InversePairsPart(data,tmp,start+mid+1,end);
//		long i=start+mid; //i指向前半段的最后一个数字
//		long j=end;       //j指向后半段的最后一个数字
//		long k=end;
//		long count=0;
//		while(i >= start && j >= start+mid+1)
//		{
//			//将两者中较小的数据放入辅助数组tmp中
//			if(data[i] > data[j])  
//			{
//				tmp[k--]=data[i--];
//				count += j-start-mid;
//			}
//			else{
//				tmp[k--]=data[j--];
//			}
//		}
//		for(;i>=start;--i)
//		{
//			tmp[k--]=data[i];
//		}
//		for(;j>=start+mid+1;--j)
//		{
//			tmp[k--]=data[j];
//		}
//		for(int s=start;s<=end;++s) //将辅助数组tmp的内容跟新到data中
//		{
//			data[s]=tmp[s];
//		}
//		return (left+right+count);
//	}
//	long InversePairs(vector<int> data) {
//		if(data.empty()){
//			return 0;
//		}
//		long len=data.size();
//		int *tmp=new int[len];//开辟辅助空间
//
//		long count=InversePairsPart(data,tmp,0,len-1);
//
//		delete[]tmp;
//		return count%1000000007;
//	}
//};
//
//void testInversePairs()
//{
//	Solution so;
//	vector<int> data;
//	data.push_back(1);
//	data.push_back(2);
//	data.push_back(3);
//	data.push_back(4);
//	data.push_back(5);
//	data.push_back(6);
//	data.push_back(7);
//	data.push_back(0);
//	int ret=so.InversePairs(data);//7
//	cout<<ret<<endl;
//}

class Solution {
public:
	int Find_one_bits(int num)  //找到两个不同的数的不同位是哪一位
	{
		int bit=0;
		while(((num&1) == 0) && bit < 8*sizeof(int))
		{
			num>>=1;
			++bit;
		}
		return bit;
	}
	void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		if(data.size() < 2){ //data的长度小于2则直接退出
			return;
		}
		*num1=0;
		*num2=0;
		int or=0;
		for(int i=0;i<data.size();i++)
		{
			or^=data[i];
		}
		int bit=Find_one_bits(or);
		for(int i=0;i<data.size();i++)
		{
			if(((data[i] >> bit)&1) == 1){  
				*num1^=data[i];
			}
			else{
				*num2^=data[i];
			}
		}
	}
};

void testFindNumsAppearOnce()
{
	Solution so;
	int num1=0;
	int num2=0;
	vector<int> data;
	//2 4 3 6 3 2 5 5
	data.push_back(2);
	data.push_back(4);
	data.push_back(3);
	data.push_back(6);
	data.push_back(3);
	data.push_back(2);
	data.push_back(5);
	data.push_back(5);
	so.FindNumsAppearOnce(data,&num1,&num2);
	cout<<num1<<" "<<num2<<endl;
}

int main()
{
	//testInversePairs();
	testFindNumsAppearOnce();
	system("pause");
	return 0;
}