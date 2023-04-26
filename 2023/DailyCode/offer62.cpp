class Solution {
public:
    int lastRemaining(int n, int m) {
        //https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/si-bu-he-xin-gong-shi-qing-song-nong-don-3vln/

        //dp[i] = (dp[i-1] + m) % i;
        int t = 0;
        for(int i = 2; i <= n; ++ i)
            t = (t + m) % i;

        return t;

    }
};