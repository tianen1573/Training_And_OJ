class Solution {
public:

    // 完全背包：数组+循环优化版本
    int minMoney(vector<int>& arr, int aim) {
        
        int f[5001];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        
        for(int i = 0; i < arr.size(); ++ i)
            for(int j = arr[i]; j <= aim; ++ j)
                f[j] = min(f[j], f[j - arr[i]] + 1);

        int ret = f[aim] >= 0x3f3f3f3f ? -1 : f[aim]; 
        return ret;
    }
};