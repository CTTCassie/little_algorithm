//集合栈
class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
        // write code here
        vector<vector<int>> res;
        vector<int> tmp;
        for(int i=0;i<ope.size();i++)    //遍历所有的集合栈
            {
            switch(ope[i][0])
                {
                case 1:      //push操作
                    if(tmp.size() != size)   //当前栈不满
                        tmp.push_back(ope[i][1]);
                    else{   //栈满
                        res.push_back(tmp);
                        tmp.clear();
                        tmp.push_back(ope[i][1]);
                    }
                    break;
                case 2:      //pop操作
                    if(!tmp.empty())   //当前栈不为空
                        tmp.pop_back();
                    else if(!res.empty())   //当前栈为空则从上一个栈pop元素
                        {
                        tmp=res[res.size()-1];
                        tmp.pop_back();
                        res.pop_back();
                    }
                    break;
                default:
                    break;
            }
        }
        if(!tmp.empty()){ 
            res.push_back(tmp);
        }
        return res;
    }
};