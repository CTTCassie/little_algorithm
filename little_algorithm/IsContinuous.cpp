//左旋
class Solution {
public:
    void Reverse(string& str,int start,int end)
        {
        while(start < end)
            {
            char tmp=str[start];
            str[start]=str[end];
            str[end]=tmp;
            start++;
            end--;
        }
    }
    string LeftRotateString(string str, int n) {
        if(str.empty())
            return "";
        int len=str.size();
        Reverse(str,0,n-1);
        Reverse(str,n,len-1);
        Reverse(str,0,len-1);
        return str;
    }
};

//扑克牌的顺子
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty())
            return false;
        
        sort(numbers.begin(),numbers.end());
        
        int len=numbers.size();
        //统计大小王的个数，大小王默认为0
        int count=0;
        //数组中是否存在间隔
        bool space=false;
        for(int i=0;i<len;i++)
            {
            if(numbers[i] == 0)
                count++;
            else if(numbers[i] == numbers[i+1])
                space=true;
        }
        if(space)  //如果存在间隔则一定是不连续的
            return false;
        int sub=numbers[len-1]-numbers[count];
        if(sub <= 4)
            return true;
        else
            return false;
    }
};
//复杂链表的复制
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode *cur=pHead;
        //复制原来所有的结点使得其连接到原始结点的后面
        while(cur != NULL)
            {
            RandomListNode *cloned=new RandomListNode(cur->label);
            cloned->next=cur->next;
            cloned->random=NULL;
            cur->next=cloned;
            cur=cloned->next;
        }
        //复制random域
        cur=pHead;
        while(cur != NULL)
            {
            RandomListNode *cloned=cur->next;
            if(cur->random != NULL){
                cloned->random=cur->random->next;
            }
            cur=cloned->next;
        }
        //拆分
        cur=pHead;
        RandomListNode *clonedcur=NULL;
        RandomListNode *clonedhead=NULL;
        if(cur != NULL){
            clonedcur=clonedhead=cur->next;
            cur->next=clonedcur->next;
            cur=cur->next;
        }
        while(cur != NULL)
            {
            clonedcur->next=cur->next;
            clonedcur=clonedcur->next;
            cur->next=clonedcur->next;
            cur=cur->next;
        }
        return clonedhead;
    }
};