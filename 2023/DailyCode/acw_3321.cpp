#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
//1. https://www.acwing.com/solution/content/131706/ newbee

#define x first
#define y second

const int N = 1e5 + 11;

pair<int, int> arr[N];

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        int n, x; cin >> n >> x;
        for(int i = 1; i <= n; ++ i)
        {
            int val; cin >> val;
            val = (val + x - 1) / x;
            arr[i] = {val, i};
        }
        sort(arr + 1, arr + 1 + n);
        
        printf("Case #%d:", t);
        for(int i = 1; i <= n; ++ i)
            printf(" %d", arr[i].y);
        printf("\n");
    }
    
    return 0;
}