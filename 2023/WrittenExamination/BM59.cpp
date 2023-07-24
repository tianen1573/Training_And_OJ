class Solution {
public:

    int res = 0;
    bool c[11] = {0}, dg[11*2] = {0}, udg[11*2] = {0}; //列，对角线，反对角线
    void dfs(int k, int n)
    {
        if(k > n)
        {
            res ++;
            return ;
        }
        // k模拟行
        for(int i = 1; i <= n; ++ i) //模拟列
        {
            // i代表列，后面两个代表对角线的截距，判断是否存在皇后
            if(c[i] || dg[k + i] || udg[k - i + n]) continue;

            c[i] = dg[k + i] = udg[k - i + n] = true;
            dfs(k + 1, n);
            c[i] = dg[k + i] = udg[k - i + n] = false;
        }
    }
    int Nqueen(int n) {
        //https://www.acwing.com/problem/content/845/
        dfs(1, n);
        return res;
    }
};