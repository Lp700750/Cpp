class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        //1 构建输出的数组
        vector<string> vecs;

        //2 使用哈希来表示手机输入键的26个字母
        unordered_map<char,string> numMap={{'2',"abc"},{'3',"def"},{'4',"ghi"},
		{'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};

        //3 构建输出数组里面元素的字符串
        string vec;

        //4 搭建回溯函数
        backTrack(numMap,digits，0，vecs，vec);
    }
    void backTrack(unordered_map<char,string> numMap,string digits,int index,
                    vector<string> vecs,string vec)
    {
        //4.1 回溯函数的终止条件

        //4.2 回溯函数的主体
        char numc=digits[index];
        for(auto aplc:numMap[numc])
        {
            vec.push_back(aplc);
        }
    }
};
