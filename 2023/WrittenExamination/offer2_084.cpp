class Solution {
private:
    vector<vector<int>> ans;
    void sol(vector<int>& nums, vector<bool>& st, int k, vector<int>& tmp)
    {
        if(k == nums.size())
        {
            ans.push_back(tmp);
            return ;
        }

        // set去重
        // 或者排序：if(i > 0 && nums[i] == nums[i - 1] && !st[i - 1]) {continue;}
        unordered_set<int> hash;
        for(int i = 0; i < nums.size(); ++ i)
        {
            if(st[i] || hash.count(nums[i]))
                continue;
            
            st[i] = true;
            tmp.push_back(nums[i]);

            hash.insert(nums[i]);
            sol(nums, st, k + 1, tmp);

            tmp.pop_back();
            st[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<bool> st(nums.size(), false);
        vector<int> tmp;
        sol(nums, st, 0, tmp);

        return ans;
    }
};