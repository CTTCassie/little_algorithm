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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(NULL == pRoot)
            return res;
        stack<TreeNode *> s1;   //利用栈后进先出的特性处理该问题
        stack<TreeNode *> s2;
        s1.push(pRoot);
        while(!s1.empty() || !s2.empty())
        {
            if(!s1.empty())
                {
                vector<int> tmp;
                while(!s1.empty())
                    {
                    TreeNode *top=s1.top();
                    s1.pop();
                    if(top->left)
                        s2.push(top->left);
                    if(top->right)
                        s2.push(top->right);
                    tmp.push_back(top->val);
                }
                res.push_back(tmp);
            }
            if(!s2.empty())
                {
                vector<int> tmp;
                while(!s2.empty())
                    {
                    TreeNode *top=s2.top();
                    s2.pop();
                    if(top->right)
                        s1.push(top->right);
                    if(top->left)
                        s1.push(top->left);
                    tmp.push_back(top->val);
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};