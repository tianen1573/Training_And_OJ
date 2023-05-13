class Solution {
public:
    int findMaxK(vector<int>& nums) {

        bool hash[2001] = {0};
        
        for(auto val : nums)
        {
            hash[val + 1000] = true;
        }

        for(int i = 1000; i >= 1; -- i)
            if(hash[i + 1000] && hash[1000 - i]) return i;
        
        return -1;
    }
};