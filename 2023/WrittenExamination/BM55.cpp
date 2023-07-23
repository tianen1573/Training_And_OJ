#include <iterator>
class Solution {
public:
    
    bool st[7] = {0};
    vector<vector<int>> res;

    void dfs(vector<int> tmp, vector<int> &vec)
    {
        bool flag = true;
        for(int i = 0; i < vec.size(); ++ i)
        {
            if(st[i])
                continue;

            flag = false;
            st[i] = true;
            tmp.push_back(vec[i]);
            dfs(tmp, vec);
            tmp.pop_back();
            st[i] = false;
        }
        if(flag)
            res.push_back(std::move(tmp)); // 移动构造
    }
    vector<vector<int> > permute(vector<int>& num) {
        // write code here
        sort(num.begin(), num.end());
        dfs(vector<int>(), num);

        return res;
    }
};