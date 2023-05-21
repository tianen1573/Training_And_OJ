#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 1010;

int arr[N], dp[N];

int n;

/*
* dp[i]： 以i为结尾的最大上升子序列的长度
* 转移方程： dp[i] = max{flag == true, dp[k]+1}, k:[1, i-1],flag == true[arr[j] < arr[i]]
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> arr[i];
    arr[0] = INT_MIN;
    
    for(int i = 1; i <= n; ++ i)
    {
        int val = 0;
        for(int j = 1; j < i; ++ j)
        {
            if(arr[j] >= arr[i]) continue;
            else val = max(val, dp[j]);
        }
        dp[i] = val + 1;
    }
    
    int ret = 1;
    for(int i = 1; i <= n; ++ i) ret = max(ret, dp[i]);
    
    cout << ret;
    
    
    return 0;
}