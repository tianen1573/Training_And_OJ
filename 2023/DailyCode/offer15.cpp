class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;

        int i = 32;
        
        while(i --)
        {
            if(n & 1) ++ cnt;
            n >>= 1;
        }

        return cnt;
        
    }
};