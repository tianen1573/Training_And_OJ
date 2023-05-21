//3167题

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 100010;

int arr[N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; ++ i) cin >> arr[i];
    sort(arr, arr + n);
    
    long long res = 0;
    
    for(int i = 0; i < n; ++ i) res += abs(arr[i] - arr[n/2]);
    
    cout << res;
    
    return 0;
}