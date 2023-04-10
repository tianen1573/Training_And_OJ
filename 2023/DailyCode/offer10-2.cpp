class Solution {
public:
    int numWays(int n) {

        if(n <= 1) return 1;
        
        int a = 1, b = 1, c;

        while(-- n)
        {
            c = (a + b) % 1000000007;
            a = b;
            b = c;
        }

        return c;

    }
};