#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

const int N = 100010;

struct str{
    int l, r;
    
    bool operator< (const str t) const
    {
        return r < t.r;//按右端点升序排序
    }
}arr[N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; ++ i) cin >> arr[i].l >> arr[i].r;
    
    sort(arr, arr + n);
    
    int end = INT_MIN;
    int cnt = 0;
    for(int i = 0; i < n; ++ i)
    {
        if(arr[i].l > end)
        {
            cnt ++;
            end = arr[i].r;
        }
    }
    
    cout << cnt;
    
    return 0;
}