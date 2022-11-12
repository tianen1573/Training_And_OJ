
//https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&&tqId=21275&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int minDistance(const string& str1, const string& str2) 
{
// word与空串之间的编辑距离为word的长度
    if (str1.empty() || str2.empty())
        return max(str1.size(), str2.size());

    int len1 = str1.size();
    int len2 = str2.size();
    vector<vector<int>> f(len1 + 1, vector<int>(len2 + 1, 0));

    //初始化距离
    for (int i = 0; i <= len1; ++i)
        f[i][0] = i;
    for (int j = 0; j <= len2; ++j)
        f[0][j] = j;
    for (int i = 1; i <= len1; ++i) 
    {
        for (int j = 1; j <= len2; ++j) 
        {
            // F(i,j) = min { F(i-1,j）+1, F(i,j-1) +1, F(i-1,j-1) +
            //(w1[i]==w2[j]?0:1) }
            // 判断word1的第i个字符是否与word2的第j个字符相等
            if (str2[j - 1] == str1[i - 1]) {
                f[i][j] = 1 + min(f[i - 1][j], f[i][j - 1]);
            //由于字符相同，所以距离不发生变化
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            } else {
                f[i][j] = 1 + min(f[i - 1][j], f[i][j - 1]);
            //由于字符不相同，所以距离+1
                f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);
            }
        }
    }
    return f[len1][len2];
}
int main() {
    string str1, str2;
    while (cin >> str1 >> str2)
        cout << minDistance(str1, str2) << endl;
    return 0;
}