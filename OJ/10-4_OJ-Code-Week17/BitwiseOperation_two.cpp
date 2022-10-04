

/*ֻ����һ�ε����� III*/
/* https://leetcode.cn/problems/single-number-iii/ */


/*
* ����Ԫ������֮��õ�����, res1 ^ res2, ���������, ��ͬ��Ϊ1, 
* ��ֻ��Ҫ�ҵ���һλ��ͬ, ���������������λ, �ֳ���������, ÿ�����ϵ������
* ���Ǹ��Դ�
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