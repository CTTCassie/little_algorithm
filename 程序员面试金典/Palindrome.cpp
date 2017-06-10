//判断链表是否是回文
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/


//方法一.先反转该链表再比较
class Palindrome {
public:
    ListNode *ReverseList(ListNode * pHead)   //反转单链表
        {
        if(pHead == NULL || pHead->next == NULL)  //空链表或者只有一个结点
            return pHead;
        ListNode *newHead=NULL;
        ListNode *cur=pHead;
        while(cur != NULL)
            {
            ListNode *newCur=cur;
            cur=cur->next;
            newCur->next=newHead;
            newHead=newCur;    //更新头
        }
        return newHead;
    }
    bool isPalindrome(ListNode* pHead) {
        // write code here
        stack<ListNode *> s;
        ListNode *cur=pHead;
        while(cur)    //先利用栈的特性反转该链表
            {
            s.push(cur);
            cur=cur->next;
        }
        cur=pHead;
        while(cur)   //链表的每个结点都和栈中的数据进行比较
            {
            ListNode *top=s.top();
            s.pop();
            if(top->val != cur->val)
                return false;
            cur=cur->next;
        }
        return true;
    }
};


//方法二.利用快慢指针的思路
class Palindrome {
public:
    //利用快慢指针法
    bool isPalindrome(ListNode* pHead) {
        // write code here
        ListNode *fast=pHead;
        ListNode *slow=pHead;
        stack<ListNode *> s;    //辅助栈
        while(fast != NULL && fast->next != NULL)  //将链表的前半部分存入栈中
            {
            s.push(slow);
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast != NULL){   //是奇数个结点,slow跳过中间节点
            slow=slow->next;
        }
        //slow遍历后半部分链表与栈中的前半部分结点进行比较
        while(slow != NULL)
            { 
            int top=s.top()->val;
            s.pop();
            if(top != slow->val)
                return false;
            slow=slow->next;
        }
        return true;
    }
};