class Same {
public:
    bool checkSam(string stringA, string stringB) {
        // write code here
        int lenA=stringA.size();
        int lenB=stringB.size();
        if(lenA != lenB)   //长度不相等
            return false;
        int hashA[256]={0};
        int hashB[256]={0};  //利用哈希表的思想统计字符出现的次数
        for(int i=0;i<lenA;i++)
            {
            hashA[stringA[i]]++;
            hashB[stringB[i]]++;
        }
        for(int k=0;k<256;k++) //比较两个哈希表中的字符出现的次数
            {
            if(hashA[k] != hashB[k])
                return false;
        }
        return true;
    }
};