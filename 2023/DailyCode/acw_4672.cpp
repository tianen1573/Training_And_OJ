#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e3 + 11;

struct vals 
{
    int d;
    int uid;
    int fir;
    int sec;
    
    string col;
}arr[N];

int T;

int main()
{
    cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        int n; cin >> n;
        for(int i = 1; i <= n; ++ i)
            cin >> arr[i].col >> arr[i].d >> arr[i].uid;
        
        sort(arr + 1, arr + 1 + n, [&](auto &a, auto &b){
           if(a.col != b.col) return a.col < b.col;
           return a.uid < b.uid;
        });
        for(int i = 1; i <= n; ++ i)
            arr[i].fir = i;
            
        sort(arr + 1, arr + 1 + n, [&](auto &a, auto &b){
           if(a.d != b.d) return a.d < b.d;
           return a.uid < b.uid;
        });
        for(int i = 1; i <= n; ++ i)
            arr[i].sec = i;
            
        int cnt = 0;
        for(int i = 1; i <= n; ++ i)
            if(arr[i].fir == arr[i].sec)
                ++ cnt;
        printf("Case #%d: %d\n", t, cnt);
    }
    
    return 0;
}