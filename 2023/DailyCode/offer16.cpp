class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1.0;//答案
        double val = x;//基数
        bool flag = n > 0 ? true : false;//正负幂

        //每次都切分成两部分 eg: 2^6
        // n    val     ans
        // 6    2^6     1
        // 3    4^3     1
        // 1    16^1    1x4
        // 0    16      1x4x16
        while(n)
        {   
            if(n % 2) ans *= val;

            val *= val;

            n /= 2;
        }

        if(!flag) ans = 1 / ans;

        return ans;

    }
};