class Zipper {
public:
    string zipString(string iniString) {
        // write code here
        int len=iniString.size();
        if(len == 0 || len == 1)
            return iniString;
        char tmp=iniString[0];
        int count=0;
        string str;
        for(int i=0;i<len;i++)
            {
              //当前的字符和之前保存的字符一致且不是最后一个字符count++
            if(iniString[i] == tmp && i != len-1)
                count++;
            else if(iniString[i] == tmp && i == len-1){
                //当前的字符和之前保存的字符一致是最后一个字符
                count++;
                str += tmp;
                str += to_string(count);
            }
            else if(iniString[i] != tmp && i != len-1){
                //当前的字符和之前保存的字符不一致，不是最后一个字符
                str += tmp;
                str += to_string(count);
                count=1;
                tmp=iniString[i];
            }
            else{
                //当前的字符和之前保存的字符不一致，是最后一个字符
                str += tmp;
                str += to_string(count);
                str += iniString[i];
                str += '1';
            }
        }
        if(str.size() < len)   //压缩之后的string比之前的string的长度小则返回压缩之后的
            return str;
        else
            return iniString;
    }
};