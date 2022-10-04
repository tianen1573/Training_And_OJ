
/*电话号码的字母组合*/
/* https://leetcode.cn/problems/letter-combinations-of-a-phone-number/ */

class Solution {
public:

    vector<string> res;
    vector<string> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string& dig, int pos, string cur)
    {
        if(pos == dig.size())
            return ;

        if(pos == dig.size() - 1)
        {
            for(int i = 0; i < arr[dig[pos] - '0'].size(); i++)
            {
                res.push_back(cur + arr[dig[pos] - '0'][i]);
            }
            return ;
        }

        for(int i = 0; i < arr[dig[pos] - '0'].size(); i++)
        {
            dfs(dig, pos + 1, cur + arr[dig[pos] - '0'][i]);
        }
    }

    vector<string> letterCombinations(string digits) {

        dfs(digits, 0, "");

        return res;

    }
};