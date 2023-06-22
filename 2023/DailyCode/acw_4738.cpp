#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

const int N = 4e5 + 11;
long long p[N], pp[N];
int r[N];

int t, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> t;
    for(int ii = 1; ii <= t; ++ ii)
    {
        cin >> n;
        for(int i = 1; i <= n; ++ i)
        {
            int x; cin >> x;
            // 不仅要统计前缀和， 这是单调栈的条件元素
            // 还要额外保存计算过程的 前缀和数组 的前缀和
            p[i] = p[i - 1] + x;
            pp[i] = pp[i - 1] + p[i];
        }
        
        stack<int> stk;
        stk.push(n+1), p[n + 1] = -1e9;
        for(int i = n; i >= 0; -- i)
        {
            while(p[i] <= p[stk.top()]) stk.pop();//找p[i]右边第一个比他小的元素位置
            
            r[i + 1] = stk.top();//i是前缀，i+1是左端点
            stk.push(i);
        }
        
        long long res = 0;
        for(int i = 1; i <= n; ++ i)
        {
            //保存的是i的右边第一个前缀和比他小的下标，连续比它大的序列的最后一个
            int j = r[i] - 1;
            res += pp[j] - pp[i - 1] - (j - i + 1) * p[i - 1];//需要去掉多余的 左端点-1 元素
        }
        
        printf("Case #%d: %lld\n", ii, res);
    }
    
    return 0;
}