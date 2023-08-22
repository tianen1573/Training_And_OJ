class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        int n = nums.size();
        set<long long> hash;

        for(int i = 0; i < n; ++ i)
        {
            auto iter = hash.lower_bound((long long)nums[i] - t);
            if(iter != hash.end() && *iter <= ((long long)nums[i] + t))
                return true;
            
            hash.insert(nums[i]);
            if(i >= k)
                hash.erase(nums[i - k]);
        }

        return false;
    }
};