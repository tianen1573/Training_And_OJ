class Solution {
public:
    int alternateDigitSum(int n) {
        
        // 当前为bcd，值为(b-c+d)，若新增一位abcd，值为(a-b+c-d) = a-(b-c+d)
        // 则 sum = n % 10 - sum, n /= 10;

        int sum = 0;
        while(n)
        {
            sum = n % 10 - sum;
            n /= 10;
        }

        return sum;

    }
};