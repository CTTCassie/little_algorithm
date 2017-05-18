//输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
 
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int len=array.size();
        vector<int> tmp;
        if(array.empty())
            return tmp;
        int left=0;
        int right=len-1;
        while(left < right)
            {
            long long cursum=array[left]+array[right];
            if(cursum == sum)
                {
                tmp.push_back(array[left]);
                tmp.push_back(array[right]);
                break;
            }
            else if(cursum > sum)
                right--;
            else  //cursum < sum
                left++;
        }
        return tmp;
    }
};

//输入一个正数s,则打印出所有和为s的连续正整数序列。

class Solution {
public:
    void Part(vector<vector<int>>& res,vector<int>& tmp,int left,int right)
        {
        for(int i=left;i<=right;i++)
            {
            tmp.push_back(i);
        }
        res.push_back(tmp);
    }
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if(sum < 3)
            return res;
        int left=1;
        int right=2;
        int mid=(1+sum)/2;
        int cursum=left+right;
        while(left < mid)
            {
            vector<int> tmp;
            if(cursum == sum)
                Part(res,tmp,left,right);
            while(left < mid && cursum > sum)
                {
                cursum -= left;
                left++;
                if(cursum == sum)
                    Part(res,tmp,left,right);
            }
            right++;
            cursum += right;
        }
        return res;
    }
};