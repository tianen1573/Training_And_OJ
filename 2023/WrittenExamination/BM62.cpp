class Solution {
public:
    // f[i]：以[i]结尾的LIS的长度
    // 遍历解法：O(N^2)
    // 队列优化: O(N*logN)
    int LIS(vector<int>& arr) {

        // 遍历
        // if(arr.size() == 0) return 0;
        // int f[1011] = {0};
        // int res = 0;
        // for(int i = 0; i < arr.size(); ++ i)
        //     for(int j = 0; j < i; ++ j)
        //     {
        //         if(arr[j] < arr[ i])
        //         {
        //             f[i] = max(f[i], f[j] + 1);
        //             res = max(res, f[i]);
        //         }
                
        //     }
        // return res + 1;

        // 队列优化
        int q[1011];
        memset(q, 0x3f, sizeof q);
        q[0] = INT_MIN;
        int len = 0;

        for(int i = 0; i < arr.size(); ++ i)
        {
            int l = 0, r = len;
            while(l < r) // 最后一个比[i]小的序列
            {
                int mid = (l + r + 1) >> 1;
                if(q[mid] < arr[i]) l = mid;
                else r = mid - 1;
            }

            len = max(len, r + 1);
            q[r + 1] = arr[i];
        }

        return len;
    }
};