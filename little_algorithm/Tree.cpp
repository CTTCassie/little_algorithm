//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同
class Solution {
public:
    bool Part(vector<int>& sequence,int start,int end)
        {
        if(start >= end)
            return true;
        int root=sequence[end]; //后序遍历的最后一个结点是根结点
        int i=end-1;
        for(;i>=start;i--)
            {
            if(sequence[i] <= root)
                break;
        }
        for(int j=i;j>=start;j--)
            {
            if(sequence[j] >= root)
                return false;
        }
        return Part(sequence,start,i) && Part(sequence,i+1,end-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        int len=sequence.size();
        return Part(sequence,0,len-1);
    }
};
//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
class Solution {
public:
    int HeightTree(TreeNode * root)  //求树的深度
        {
        if(root == NULL)
            return 0;
        int leftsize=HeightTree(root->left)+1;
        int rightsize=HeightTree(root->right)+1;
        return leftsize>rightsize?leftsize:rightsize;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
            return true;
        int left=HeightTree(pRoot->left);
        int right=HeightTree(pRoot->right);
        if(abs(right-left) > 1)
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};