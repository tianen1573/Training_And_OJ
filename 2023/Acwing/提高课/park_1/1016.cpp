#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1010;

int h[N], f[N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> h[i];
        f[i] = h[i];
    }

    int res = 0;
    for(int i = 1; i <= n; ++ i)
    {
        res = max(res, f[i]);
        for(int j = 1; j < i; ++ j)
            if(h[i] > h[j])
            {
                f[i] = max(f[i], f[j] + h[i]);
                res = max(res, f[i]);
            }
    }

    cout << res;


    return 0;
}
