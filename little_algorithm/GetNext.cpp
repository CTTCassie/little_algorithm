//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        while(pNode->right != NULL)  //如果存在右子树，则cur一直遍历到最左节点
            {
            TreeLinkNode *cur=pNode->right;
            while(cur->left != NULL)
                {
                cur=cur->left;
            }
            return cur;
        }
        while(pNode->next != NULL)  //如果不存在右子树，则找第一个当前节点是父节点左孩子的节点
            {
            if(pNode->next->left == pNode)
                {
                return pNode->next;;
            }
            pNode=pNode->next;
        }
        return NULL;  //遍历到根结点还未找到则返回NULL
    }
};