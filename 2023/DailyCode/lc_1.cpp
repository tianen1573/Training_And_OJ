class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> arr;
        for(int i = 0 ; i < nums.size(); ++ i)
            arr.push_back({nums[i], i});
        sort(arr.begin(), arr.end());

        int left = 0, rig = nums.size() - 1;
        while(left < rig && arr[left].first + arr[rig].first != target)
        {
            if(arr[left].first + arr[rig].first > target) -- rig;
            else ++ left;
        }

        if(left == rig) return vector<int>();
        else return vector<int>() = {arr[left].second, arr[rig].second};
    }
};