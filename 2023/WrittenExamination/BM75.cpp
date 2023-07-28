class Solution {
public:

    //f[i][j]：A的前i变成B的前j的最小操作树
    //f[i][j] = min{
    //f[i - 1][j] + 1 : A的前i-1操作后能和B的前j匹配，则只能把i删了，删
    //f[i][j - 1]: 只能给A加一个B[j]，增
    //f[i -1][j - 1] : 如果A[i] != B[j], 需要改A[i]，即+1， 否则不变  }
    int editDistance(string str1, string str2) {
        
        int f[1011][1011];
        // for(int i = 0; i <= str2.size(); ++ i) f[0][i] = i;
        // for(int i = 0; i <= str1.size(); ++ i) f[i][0] = i;
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;

        for(int i = 0; i < str1.size(); ++ i)
            for(int j = 0; j < str2.size(); ++ j)
            {
                //增删
                f[i + 1][j + 1] = min(f[i][j + 1], f[i + 1][j]) + 1;
                //修改
                if(str1[i] == str2[j]) f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j]);
                else f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j] + 1);
            }

        return f[str1.size()][str2.size()];
    }
};