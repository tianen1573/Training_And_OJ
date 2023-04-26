class Solution {
public:
    int cuttingRope(int n) {

        //数学
        // if(n <= 3) return n-1;

        // int a = n / 3, b = n % 3;

        // if(b == 0) return (int)pow(3, a);
        // if(b == 1) return (int)pow(3, a - 1) * 4;
        // else return (int)pow(3, a) * 2;

        //DP
        //dp[i]:长度为i时的能分割出来最大成绩，绳子可以被切割成[2,n]份
        //则一个dp[i]能从两个地方转移得到
        //1. 从dp[j], dp[i] = dp[j] * (i - j); 从已经切割好的里搞
        //2. 重新切割， dp[i] = j * (i - j);
        int *dp = new int[n + 1];
        dp[1] = 1;

        for(int i = 2; i <= n; ++ i)
            for(int j = 1; j <= i - 1; ++ j)
            {
                int tmp = max(dp[j] * (i - j), j * (i - j));
                dp[i] = max(dp[i], tmp);
            }

        return dp[n];
                
    }
};