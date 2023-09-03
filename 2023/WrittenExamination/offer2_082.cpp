class Solution {

    vector<vector<int>> ans;
    void sol(vector<int>& candidates, int tar, int sum, int idx, vector<int>& tmp)
    {
        if(sum == tar)
        {
            ans.push_back(tmp);
            return ;
        }
        
        for(int i = idx + 1; i < candidates.size(); ++ i)
        {
            // 元素不重复
            // 假设当前入数组的元素是第k个元素，那么我们需要保证所有可行的第k个元素不重复
            // 因为我们排过序了，所以只要保证candidates[i] != candidates[i - 1]，就可以保证不重复
            // 若相等：
            // 1. 若[i]可入数组， 则[i + 1]不能作为第k个，重复了
            // 2. 若[i]不可入数组，则[i + 1]也不能入
            //不排序，可以使用set记录第k次的的元素
            if(i > idx + 1 && candidates[i] == candidates[i - 1])
                continue;
            // sum < tar
            if(sum + candidates[i] > tar)
                break;
            
            tmp.push_back(candidates[i]);
            sol(candidates, tar, sum + candidates[i], i, tmp);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        sol(candidates, target, 0, -1, tmp);

        return ans;
    }
};