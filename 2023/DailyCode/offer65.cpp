class Solution {
public:
    int add(int a, int b) {

        int m = 0, n = 0;
        int ans = 0;

        for(int i = 0; i < 32; ++ i)
        {
            int sum = (a & 1) + (b & 1) + m;

            m = sum / 2;
            n = sum % 2;

            a >>= 1;
            b >>= 1;
            
            ans |= (n << i);

        }

        return ans;
    }
};