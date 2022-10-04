

/*只出现一次的数字 III*/
/* https://leetcode.cn/problems/single-number-iii/ */


/*
* 所有元素相与之后得到的是, res1 ^ res2, 又异或运算, 不同才为1, 
* 则只需要找到哪一位不同, 根据这个二进制数位, 分成两个集合, 每个集合的异或结果
* 就是各自答案
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int val = 0;
        for(auto& x : nums)
        {
            val ^= x;
        }
        int count = 0;
        while(!(val >> count & 1))
        {
            count++;
        }
        int res1 = 0, res2 = 0;

        for(auto& x : nums)
        {
            if(x >> count & 1)
            {
                res1 ^= x;
            }
            else
            {
                res2 ^= x;
            }
        }

        return vector<int>{res1,res2};
    }
};