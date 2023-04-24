class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int arr[32] = {0};

        for(auto num : nums)
            for(int i = 0; i < 32; ++ i)
            {
                if((num >> i) & 1) ++ arr[i];
            }
        
        int ret = 0;
        for(int i = 0; i < 32; ++ i)
        {
            if(arr[i] % 3)
                ret |= (1 << i);
        }

        return ret;

    }
};