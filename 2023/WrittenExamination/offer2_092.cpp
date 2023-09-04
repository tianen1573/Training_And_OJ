class Solution {
public:
    // f[N][2] : 到第i个字符时，0-i是有序的; [i][0]：第i个字符是0，[i][1]第i个字符是1
    // f[i][0] = f[i - 1][0] + i != '0'
    // f[i][1] = min(f[i - 1][0], f[i - 1][1]) + i != '1'
    int minFlipsMonoIncr(string s) {

        vector<vector<int>> f(s.size(), vector<int>(2, 0));
        f[0][0] = (s[0] != '0');
        f[0][1] = (s[0] != '1');

        int len = s.size();
        for(int i = 1; i < len; ++ i)
        {
            f[i][0] = f[i - 1][0] + (s[i] != '0');
            f[i][1] = min(f[i - 1][0], f[i - 1][1]) + (s[i] != '1');
        }

        int ret = min(f[len - 1][0], f[len - 1][1]);
        return ret;
    }
};