class Solution {
public:
    // f[i]：以[i]结尾的LIS的长度
    // 遍历解法：O(N^2)
    int LIS(vector<int>& arr) {

        if(arr.size() == 0) return 0;

        int f[1011] = {0};
        int res = 0;
        for(int i = 0; i < arr.size(); ++ i)
            for(int j = 0; j < i; ++ j)
            {
                if(arr[j] < arr[ i])
                {
                    f[i] = max(f[i], f[j] + 1);
                    res = max(res, f[i]);
                }
                
            }
        return res + 1;

    }
};