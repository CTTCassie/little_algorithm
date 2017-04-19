#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

int PastSort(int *arr,int start,int end)
{
	int left=start;
	int right=end;
	int key=arr[end];
	while(left < right)
	{
		//左边找比key大的值，找到后交换
		while(left < right && arr[left] <= key)
		{
			++left;
		}
		swap(arr[left],arr[right]);
		//右边找比key小的值，找到后交换
		while(left < right && arr[right] >= key)
		{
			--right;
		}
		swap(arr[right],arr[left]);
	}
	arr[left]=key;
	return left;
}
int MorethanHalfnum(int *arr,int sz)
{
	//判断数组是否合法
	if(NULL == arr || sz <= 0)
	{
		return 0;
	}
	int mid=sz/2;
	int start=0;
	int end=sz-1;
	int index=PastSort(arr,start,end);
	while(index != mid)
	{
		if(index > mid)
		{
			end=index-1;
			index=PastSort(arr,start,end);
		}
		else//index <= mid
		{
			start=index+1;
			index=PastSort(arr,start,end);
		}
	}
	int ret=arr[mid];
	//统计该中位数出现的次数
	int count=0;
	for(int i=0;i<sz;i++)
	{
		if(arr[i] == ret)
			count++;
	}
	//出现的次数是否超过数组总长度的一半
	if(2*count <= sz) 
		return 0;
	else
		return ret;
}
int MorethanHalfnum(int,int *arr,int sz)
{
	//判断数组是否合法
	if(NULL == arr || sz <= 0)
	{
		return 0;
	}
	int result=arr[0];
	int count=1;
	//result保存数字，count保存该数字出现的次数
	//如果下一个数字和之前保存的数字相同则count++
	//如果下一个数字和之前保存的数字不同则count--
	//如果count==0，则修改result的值并将count置为1
	for(int i=0;i<sz;i++)
	{
		if(count == 0)
		{
			result=arr[i];
			count=1;
		}
		else if(arr[i] == result)
		{
			count++;
		}
		else
		{
			count--;
		}
	}
	return result;
}
int main()
{
	int arr[]={1,2,3,2,2,2,5,4,2};
	//int arr[]={4,2,1,4,2,4};
	int sz=sizeof(arr)/sizeof(arr[0]);
	//int ret=MorethanHalfnum(arr,sz);
	int ret=MorethanHalfnum(0,arr,sz);
	if(ret != 0)
		cout<<"more than half nums is "<<ret<<endl;
	else
		cout<<"not exist"<<endl;
	system("pause");
	return 0;
}