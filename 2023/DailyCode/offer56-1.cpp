class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {

        vector<int> ans(2);

        int val = 0;

        for(auto i : nums)
            val ^= i;
        
        int i = 0;
        while(!(val & 1))
        {
            ++ i;
            val >>= 1;
        }

        for(auto num : nums)
        {
            if((num >> i) & 1)  ans[0] ^= num;
            else ans[1] ^= num;
        }

        return ans;

    }
};