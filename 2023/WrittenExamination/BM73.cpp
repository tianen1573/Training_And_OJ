class Solution {
public:

    int getLongestPalindrome(string A) {
        
        // 马拉车算法 N

        // 枚举 中心到两边 N^2
        int ret = 1, cnt = 1;
        for(int i = 0; i < A.size(); ++ i)
        {
            int l = i - 1, r = i + 1;
            int len = 1;
            while(l >= 0 && r < A.size())
            {
                cnt += 2;
                if(A[l] == A[r]) len += 2;
                else break;
                -- l, ++ r;
            }
            ret = max(ret, len);
            l = i, r = i + 1;
            len = 0;
            while(l >= 0 && r < A.size())
            {
                if(A[l] == A[r]) len += 2;
                else break;

                -- l, ++ r;
            }
            ret = max(ret, len);
        }
        cout << cnt;
        return ret;

        // // dp 两边到中心 N^2
        // bool f[1011][1011] = {false};
        // for(int i = 0; i <= A.size(); ++ i)
        //     f[i][i] = true;
        
        // int ret = 1, cnt = 0;
        // for(int len = 2; len <= A.size(); ++ len)
        //     for(int i = 0; i + len - 1 < A.size(); ++ i)
        //     {
        //         ++ cnt;
        //         int j = i + len - 1;
        //         if(A[i] != A[j]) continue;

        //         if(len == 2) f[i][j] = true;
        //         else f[i][j] = f[i+1][j-1];

        //         if(f[i][j]) ret = len;
        //     }
        
        // cout << cnt;
        // return ret;
    }
};