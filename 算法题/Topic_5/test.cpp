//Jolly.Roger

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    string::iterator ptr1=str.begin();
    string::iterator ptr2=str.begin();
    while(ptr2!=str.end())
    {
        if(*ptr2==' ')
        {
            ptr1=ptr2+1;
        }
        ptr2++;
    }
    cout<<ptr2-ptr1<<endl;

    return 0;
}
// 64 位输出请用 printf("%lld")
