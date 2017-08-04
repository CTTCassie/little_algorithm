//想法一、利用快排的思想
int PartSort(int *arr, int start, int end)
{
	int left = start;
	int right = end;
	int key = arr[end];   //选取关键字
	while (left < right)
	{
		while (left < right && arr[left] <= key)  //左边找比key大的值
		{
			++left;
		}
		while (left < right && arr[right] >= key)  //右边找比key小的值
		{
			--right;
		}
		if (left < right)
		{
			swap(arr[left], arr[right]);  //找到之后交换左右的值
		}
	}
	swap(arr[right], arr[end]);
	return left;
}
//求一个无序数组的中位数
int GetMidNumNoSort1(int *arr,int size)
{
	assert(arr);
	int start = 0;
	int end = size - 1;
	int mid = (size - 1) / 2;
	int div = PartSort(arr,start,end);
	while (div != mid)
	{
		if (mid < div)   //左半区间找
			div = PartSort(arr, start, div - 1);
		else    //左半区间找
			div = PartSort(arr, div + 1, end);
	}
	return arr[mid];   //找到了
}

//想法二、建小堆来实现
#include<queue>
#include<vector>
int GetMidNumNoSort2(int *arr, int size)
{
	assert(arr);
	int len = (size + 1) / 2;
	struct Compare    //建小堆
	{
		int operator()(int left, int right)
		{
			return left > right;
		}
	};
	priority_queue<int, vector<int>, Compare> heap;
	//先以整个数组的前len个元素建小堆
	for (int i = 0; i < len; i++)
	{
		heap.push(arr[i]);
	}
	for (int i = len; i < size; i++)
	{
		if (arr[i] > heap.top())  //比堆顶元素大则更新该小堆
		{
			heap.pop();
			heap.push(arr[i]);
		}
	}
	if (!heap.empty())
	{
		return heap.top();
	}
}

void TestMidNum()
{
	int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1 };   // 中位数5
	//int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };  //中位数4或者5,5
	int size = sizeof(arr) / sizeof(arr[0]);
	int mid = GetMidNumNoSort1(arr, size);  
	cout << "Mid ? "<<mid<<endl;
}