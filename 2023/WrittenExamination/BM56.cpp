#include <iterator>
class Solution {
public:
    
    bool st[7] = {0};
    vector<vector<int>> res;
    set<vector<int>> hash;

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
        if(flag && hash.find(tmp) == hash.end())
        {
            hash.insert(tmp);
            res.push_back(std::move(tmp)); // 移动构造
        }
    }
    vector<vector<int> > permuteUnique(vector<int>& num) {
        // write code here
        sort(num.begin(), num.end());
        dfs(vector<int>(), num);

        return res;
    }
};