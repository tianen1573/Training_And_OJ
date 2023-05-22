#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

//单调上升 + 单调下降
//f[i]：以arr[i]结尾的最长上升/下降子序列
//f[i]可由f[1~i-1]转移而来
//g[i]同理


int f[N], rf[N];
int arr[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    for(int i = 1; i <= n; ++ i) 
        cin >> arr[i];

    for(int i = 1; i <= n; ++ i) f[i] = rf[i] = 1;

    int res = 0;

    //上升子序列
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j < i; ++ j)
            if(arr[i] > arr[j])
                f[i] = max(f[i], f[j] + 1);

    //下降子序列
    for(int i = n; i >= 1; -- i)
        for(int j = n; j > i; -- j)
            if(arr[i] > arr[j])
                rf[i] = max(rf[i], rf[j] + 1);

    for(int i = 1; i <= n; ++ i) res = max(res, f[i] + rf[i]);

    cout << res - 1 << endl;


    return 0;
}
