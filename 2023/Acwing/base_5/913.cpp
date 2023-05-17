#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

int arr[N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; ++ i) cin >> arr[i];
    sort(arr, arr + n);
    
    long long res = 0;
    for(int i = 0; i < n ; ++ i)
    {
        res += (arr[i] * (n - i - 1));
    }
    
    cout << res;
    
    return 0;
}