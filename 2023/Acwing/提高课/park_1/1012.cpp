#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define x first
#define y second
using namespace std;


//把北岸的港口按照南岸的友好城市排序， 求排序后的北岸最长上升子序列

const int N = 5010;

pair<int, int> h[N];
int f[N];

int n;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.x < b.x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> h[i].x >>h[i].y;
    sort(h + 1, h + n + 1, cmp);

    int res = 0;
    for(int i = 1; i <= n; ++ i)
    {
        f[i] = 1;
        for(int j = 1; j < i; ++ j)
            if(h[i].y > h[j].y)
            {
                f[i] = max(f[i], f[j] + 1);
                res = max(f[i], res);
            }
    }

    cout << res;

    return 0;
}
