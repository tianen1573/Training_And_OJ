

/*只出现一次的数字 II*/
/* https://leetcode.cn/problems/single-number-ii/ */


/*
* 统计二进制数位, 1的个数
* 模3, 得1, 代表单身狗此位为1, 否则为0
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int bit[32] = {0};

        for(auto x : nums)
        {
            for(int i = 0; i < 32; i++)
            {
                if(x >> i & 1)
                {
                    bit[i]++;
                }
            }
        }
        for(auto &x : bit)
        {
            x %= 3;
        }

        int res = 0;
        for(int i = 31; i >= 0; --i)
        {
            res <<= 1;
            if(bit[i] == 1)
            {
                res += 1;
            }
        }

        return res;

    }
};