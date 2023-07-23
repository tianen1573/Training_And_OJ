class Solution {
public:

    // bool st[100001] = {0};
    // vector<int> countBits(int n) {

    //     vector<int> res(n + 1);
    //     res[0] = 0;

    //     for(int i = 1; i <= n; ++ i)
    //     {
    //         // 0. 遍历过
    //         if(st[i]) continue;
            
    //         // 1. 求1的个数
    //         int cnt = 0;
    //         for(int j = 0; j < 32; ++ j)
    //             if((i >> j) & 1)
    //                 ++ cnt;
    //         // 2. 遍历
    //         long long cur = i;
    //         while(cur <= n)
    //         {
    //             st[cur] = true;
    //             res[cur] = cnt;
    //             cur <<= 1;
    //         }
    //     }

    //     return res;
    // }

    //by评论区
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);
        for(int i = 0; i <= n; ++ i)
            res[i] = res[i >> 1] + (i & 1);
        
        return res;
    }
};