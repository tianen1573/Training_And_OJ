class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left(nums.size() + 2, 0);
        vector<int> rig(nums.size() + 2, 0);

        for(int i = 0; i < nums.size(); ++ i)
            left[i + 1] = left[i] + nums[i];
        for(int i = nums.size() - 1; i >= 0; -- i)
            rig[i + 1] = rig[i + 1 + 1] + nums[i];
        
        for(int i = 0; i < nums.size(); ++ i)
            if(left[i - 1 + 1] == rig[i + 1 + 1])
                return i;
        
        return -1;
    }
};