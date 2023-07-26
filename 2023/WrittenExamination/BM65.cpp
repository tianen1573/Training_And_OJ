// class Solution {
// public:
    
//     // f[i][j] : 从前i，j个选元素，构成的LCS
//     // = max{f[i-1][j], f[i][j-1], f[i-1][j-1] + 1([i] == [j])}
//     string LCS(string s1, string s2) {
        
//         int n = s1.size(), m = s2.size();
//         vector<vector<string>> f(n + 1, vector<string>(m + 1, ""));

//         for(int i = 0; i < n; ++ i)
//             for(int j = 0; j < m; ++ j)
//             {
//                 if(f[i + 1][j].size() > f[i][j + 1].size())
//                     f[i + 1][j + 1] = f[i + 1][j];
//                 else 
//                     f[i + 1][j + 1] = f[i][j + 1];
                
//                 if(s1[i] == s2[j] && f[i][j].size() >= f[i + 1][j + 1].size())
//                     f[i + 1][j + 1] = f[i][j] + s1[i];
//             }
//         if("" == f[n][m]) f[n][m] = "-1";

//         return f[n][m];
//     }
// };
// 长字符串+长LCS时，需要保存的字符串太多，爆栈
// 改为记录位置：官解
class Solution {
public:
    string x = "";
    string y = "";
    //获取最长公共子序列
    string ans(int i, int j, vector<vector<int>>& b){ 
        string res = "";
        //递归终止条件
        if(i == 0 || j == 0)
            return res;
        //根据方向，往前递归，然后添加本级字符
        if(b[i][j] == 1){
            res += ans(i - 1, j - 1, b);
            res += x[i - 1];
        }
        else if(b[i][j] == 2)
            res += ans(i - 1, j, b);
        else if(b[i][j] == 3)
            res += ans(i,j - 1, b);
        return res;
    }
    string LCS(string s1, string s2) {
        //特殊情况
        if(s1.length() == 0 || s2.length() == 0) 
            return "-1";
        int len1 = s1.length();
        int len2 = s2.length();
        x = s1;
        y = s2;
        //dp[i][j]表示第一个字符串到第i位，第二个字符串到第j位为止的最长公共子序列长度
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        //动态规划数组相加的方向
        vector<vector<int>> b(len1 + 1, vector<int>(len2 + 1, 0));
        //遍历两个字符串每个位置求的最长长度
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                //遇到两个字符相等
                if(s1[i - 1] == s2[j - 1]){
                    //考虑由二者都向前一位
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    //来自于左上方
                    b[i][j] = 1;
                }
                //遇到的两个字符不同
                else{
                    //左边的选择更大，即第一个字符串后退一位
                    if(dp[i - 1][j] > dp[i][j - 1]){
                        dp[i][j] = dp[i - 1][j];
                        //来自于左方
                        b[i][j] = 2;
                    }
                    //右边的选择更大，即第二个字符串后退一位
                    else{
                        dp[i][j] = dp[i][j - 1];
                        //来自于上方
                        b[i][j] = 3;
                    }
                }
            }
        }
        //获取答案字符串
        string res = ans(len1, len2, b);
        //检查答案是否位空
        return  res != "" ? res : "-1";
    }
};