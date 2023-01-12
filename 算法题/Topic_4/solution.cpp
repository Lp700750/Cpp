//验证回文串
//Jolly.Roger
class Solution 
{
public:
    bool isPalindrome(string s)
    {
        if(s.size()==1)
        {
            return true;
        }
        string desStr;
        string::iterator ptr1=s.begin();
        while(ptr1!=s.end())
        {
            if(*ptr1>47&&*ptr1<58)
            {
                desStr.push_back(*ptr1);
            }
            else if(*ptr1>64&&*ptr1<91)
            {
                char c=*ptr1+32;
                desStr.push_back(c);
            }
            else if(*ptr1>96&&*ptr1<123)
            {
                desStr.push_back(*ptr1);
            }
            else
            {
            
            }
            ++ptr1;
        }
        string::iterator ptr2=desStr.begin();
        string::iterator ptr3=desStr.end()-1;
        while(ptr2<=ptr3)
        {
            if((*ptr2)!=(*ptr3))
            {
                return false;
            }
            ptr2++;
            ptr3--;
        }
        return true;
        

    }
};
