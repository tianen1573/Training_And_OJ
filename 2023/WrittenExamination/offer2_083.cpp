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
        for(int i = 0; i < nums.size(); ++ i)
        {
            if(st[i]) 
                continue;
            
            st[i] = true;
            tmp.push_back(nums[i]);
            sol(nums, st, k + 1, tmp);
            tmp.pop_back();
            st[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<bool> st(nums.size(), false);
        vector<int> tmp;
        sol(nums, st, 0, tmp);

        return ans;
    }
};