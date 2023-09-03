class Solution {
private:
    vector<vector<int>> ans;
    // 和顺序无关
    void sol(vector<int>& candidates, int target, int pos, int sum, vector<int>& tmp)
    {
        if(sum == target)
        {
            ans.push_back(tmp);
            return ;
        }

        for(int i = pos; i < candidates.size(); ++ i)
        {
            if(sum + candidates[i] > target)
                continue;
            
            tmp.push_back(candidates[i]);
            sol(candidates, target, i, sum + candidates[i], tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> tmp;
        sol(candidates, target, 0, 0, tmp);

        return ans;
    }
};