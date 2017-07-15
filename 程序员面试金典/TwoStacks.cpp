//双栈排序
class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // write code here
        if(numbers.size() <= 1)   //没有结点或者只有一个结点
            return numbers;
        vector<int> tmp;
        tmp.push_back(numbers[0]);  //将第一个结点插入到tmp里面去
        for(int i=1;i<numbers.size();i++)
            {
            if(numbers[i] <= tmp.back())
                tmp.push_back(numbers[i]);
            else{
                vector<int>::iterator it=tmp.begin();
                while(it != tmp.end())
                    {
                    if(*it < numbers[i]){
                        break;
                    }
                    it++;
                }
                tmp.insert(it,numbers[i]);
            }
        }
        return tmp;
    }
};