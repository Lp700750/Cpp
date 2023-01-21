class Solution 
{
public:
    int strtoint(string str)
    {
        int result=0;
        for(int i=0;i<str.size();++i)
        {
            result=result*10+(str[i]-'0');
        }
        return result;
    }
    string multiply(string num1, string num2) 
    {
        //第一步：将字符串的数字转换成整型数字
        int data1=strtoint(num1);
        int data2=strtoint(num2);
        
        //第二步：将两个整型数字进行相乘
        unsigned long long int value(ULL)=data1*data2;
        
        //第三步：将相乘的结果转化成字符串
        string desStr;
        if(0==value)
        {
            desStr.push_back('0');
        }

        while(value)
        {
            char c=(value%10+'0');
            desStr.push_back(c);
            value=value/10;
        }
        reverse(desStr.begin(),desStr.end());
        return desStr;
    }
};
