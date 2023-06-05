#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 11;

int arr[N], head[N];
int f[N][10];//从前i个中选，以j结尾的最长子序列

int n;

int getHead(int x)
{
    while(x >= 10) x /= 10;

    return x;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> arr[i];
        head[i] = getHead(arr[i]);
    }

    for(int i = 1; i <= n; ++ i)
    {
        int a = head[i], b = arr[i] % 10;
        memcpy(f[i], f[i - 1], sizeof f[i]);//优化成一维数组

        f[i][b] = max(f[i - 1][b], f[i - 1][a] + 1);
    }

    //n - 最长子序列的长度 就是需要删除的长度
    int maxv = 0;
    for(int i = 0; i < 10; ++ i) maxv = max(maxv, f[n][i]);
    cout << n - maxv << endl;

    return 0;
}