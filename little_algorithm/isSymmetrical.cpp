//请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return true;
        queue<TreeNode *> q1,q2;  //辅助队列q1和q2
        q1.push(pRoot->left);
        q2.push(pRoot->right);
        while(!q1.empty() && !q2.empty())
            {
            TreeNode *top1=q1.front();
            q1.pop();
            TreeNode *top2=q2.front();
            q2.pop();
            if(top1 == NULL && top2 == NULL)  //两个队列的元素都为空
                continue;
            if(top1 == NULL || top2 == NULL)  //只有一边为空
                return false;
            if(top1->val != top2->val)  //两个队顶元素不相等
                return false;
            q1.push(top1->left);  //q1先左后右
            q1.push(top1->right);
            q2.push(top2->right); //q2先右后左
            q2.push(top2->left);
        }
        return true; 
    }
};