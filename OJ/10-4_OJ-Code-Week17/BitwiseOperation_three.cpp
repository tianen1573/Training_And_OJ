

/*ֻ����һ�ε����� II*/
/* https://leetcode.cn/problems/single-number-ii/ */


/*
* ͳ�ƶ�������λ, 1�ĸ���
* ģ3, ��1, ��������λΪ1, ����Ϊ0
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