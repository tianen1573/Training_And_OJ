#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010;

struct str{
    int w, s;
    
    bool operator< (const str& t) const
    {
        return w + s < t.w + t.s;
    }
}arr[N];

int n;


//w+s大的放下面，别问我为什么
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; ++ i) cin >> arr[i].w >> arr[i].s;
    sort(arr, arr + n);
    
    int sum = 0;
    int res = -0x3f3f3f3f;
    for(int i = 0; i < n; ++ i)
    {
        res  = max(res, sum - arr[i].s);
        sum += arr[i].w; 
    }
    
    cout << res;
    
    return 0;
}