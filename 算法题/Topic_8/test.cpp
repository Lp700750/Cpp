class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        int numStr1=num1.size()-1;
        int numStr2=num2.size()-1;
        int add=0;
        string desStr;
        while(numStr1>=0||numStr2>=0||add!=0)
        {
            int ret1=numStr1>=0?num1[numStr1]-'0':0;
            int ret2=numStr2>=0?num2[numStr2]-'0':0;
            int result=(ret1+ret2+add)%10;
            add=(ret1+ret2+add)/10;
            char c=result+'0';
            desStr.push_back(c);
            numStr1--;
            numStr2--;
        }
        reverse(desStr.begin(),desStr.end());
        return desStr;
    }
};
