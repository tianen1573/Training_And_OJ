class Solution {

private:

    vector<vector<int>> ans;

    void sol(vector<int>& nums, int pos, vector<int>& tmp)
    {
        ans.push_back(tmp);
        for(int i = pos + 1; i < nums.size(); ++ i)
        {
            tmp.push_back(nums[i]);
            sol(nums, i, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> tmp;
        sol(nums, -1, tmp);

        return ans;
    }
};