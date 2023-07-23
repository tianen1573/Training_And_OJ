class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //O(1)空间复杂度

        int cnt[32] = {0};

        for(auto val : nums)
        {
            for(int i = 0; i < 32; ++ i)
            {
                cnt[i] += (val >> i) & 1;
            }
        }

        int res = 0;
        for(int i = 0; i < 32; ++ i)
            res += (cnt[i] % 3) << i;

        return res;
    }
};