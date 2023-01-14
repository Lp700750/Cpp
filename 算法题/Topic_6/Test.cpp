//字符串当中第一个第一次出现的字符
//Jolly.Roger

class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char,int> sNum;
        for(char c:s)
        {
            ++sNum[c];
        }
        for(int i=0;i<s.size();i++)
        {
            if(1==sNum[s[i]])
            {
                return i;
            }
        }
        return -1;
    }
};
