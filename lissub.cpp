#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

////O(n^n)
//int longest_suborder(int *arr,int size)
//{
//	int *tmp=new int[size];
//	//以a1作为末元素的递增子序列的长度为1
//	tmp[0]=1;
//	for(int i=1;i<size;i++)
//	{
//		//tmp[i]的最小值为1 
//		tmp[i]=1;
//		for(int j=0;j<i;j++)
//		{
//			if(arr[j] < arr[i] && tmp[j] > tmp[i]-1)
//			{
//				tmp[i]=tmp[j]+1;
//			}
//		}
//	}
//	return tmp[size-1];
//}

//O(n*lgn)
int longest_suborder(int *arr,int size)
{
	int *tmp=new int[size+1];
	tmp[0]=-10000;//tmp[0]为最小
	tmp[1]=arr[0];
	int len=1; //当前最大递增子序列的长度
	int left=0;
	int right=0;
	int mid=0;
	for(int i=1;i<size;i++)
	{
		right=len;
		//二分查找的方式
		while(left <= right)
		{
			//mid=(left+right)/2;
			mid=(right-left)/2+left;
			if(tmp[mid] < arr[i])
				left=mid+1;
			else
				right=mid-1;
		}
		tmp[left]=arr[i];
		//更新最长子序列的长度
		if(left > len)
		{
			len++;
		}
	}
	return len;
}

int main()
{
	int arr[]={2,1,6,4,5,2,7,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	int ret=longest_suborder(arr,size);
	cout<<ret<<endl;
	system("pause");
	return 0;
}