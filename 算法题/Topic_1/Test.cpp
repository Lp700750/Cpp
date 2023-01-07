//找出字符串当中第一个第一次出现的字符
//Jolly.Roger

#include <iostream>
#include<string>
using namespace std;
class getFirstchar
{
public:
    getFirstchar(const string s)
        :_s(s)
    {}
    char* getFirst()
    {
        for(int i=0;i<_s.size();i++)
        {
            int cnt=0;
            for(int j=0;j<_s.size();j++)
            {
                if(_s[i]==_s[j])
                {
                    cnt++;
                    if(2==cnt)
                    {
                        break;
                    }
                }
            }
            if(1==cnt)
            {
                return &_s[i];
            }
        }
        return nullptr;
    }
private:
    string _s;
};
int main() 
{
    string s;
    while(cin>>s)
    {
        getFirstchar s1(s);
        char* cNum=s1.getFirst();
        if(cNum==nullptr)
        {
            cout<<-1;
        }
        else
        {
            cout<<*cNum;
        }
    }

    return 0;
}
