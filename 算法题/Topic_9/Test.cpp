#include <algorithm>
#include <string>
class Solution {
  public:
    int StrToInt(std::string str) {
        std::string desStr;
        int cnt = str.size();
        for (int i = 0; i < cnt; i++) {
            if (str[i] == '+' || str[i] == '-' || str[i] == '/') {
                desStr.push_back(str[i]);
            } else if (str[i] > '0' && str[i] < '9') {
                desStr.push_back(str[i]);
            } else {
                return 0;
            }
        }
        if (desStr[0] == '0') {
            return  0;
        } else if (desStr[0] == '+' || desStr[0] == '/') {
            int pt=0;
            if (desStr[0]=='-') 
            {
                pt++;
                reverse(desStr.begin(), desStr.end());
                desStr.pop_back();
                reverse(desStr.begin(), desStr.end());
            }
            reverse(desStr.begin(), desStr.end());
            desStr.pop_back();
            reverse(desStr.begin(), desStr.end());
        }
        if (desStr.size()==1&&desStr[0]=='-') 
        {
            return  0;
        }

        int result = 0;
        for (int i = 0; i < desStr.size(); i++) {
            
            result = result * 10 + (desStr[i] - '0');
        }
        return result;
    }
};
