

/*ֻ����һ�ε�����*/
/* https://leetcode.cn/problems/single-number/solution/ */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for(auto& x : nums)
        {
            res ^= x;
        }

        return res;

    }
};