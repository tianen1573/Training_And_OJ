class Solution {
public:

    int Fibonacci(int n) {
        
        if(n <= 2) return 1;

        int a = 1, b = 1, c = 0;

        for(int i = 3; i <= n; ++ i)
        {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};