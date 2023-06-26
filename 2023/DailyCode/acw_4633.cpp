#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
//最大的小于2倍的值，最大的小于它的值，-1
//快慢指针

const int N = 1e5 + 11;
struct
{
    int gra, id, fat;
}arr[N];

int T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        int n; cin >> n;
        for(int i = 1; i <= n; ++ i)
        {
            int val; cin >> val;
            arr[i].gra = val, arr[i].id = i;
        }
        sort(arr + 1, arr + 1 + n, [&](auto &a, auto &b)
        {
            return a.gra > b.gra;
        });
        arr[0] = {-1, 0, 0};
        int left = 1;//慢指针
        for(int i = 1; i <= n; ++ i)
        {
            while(arr[left].gra > arr[i].gra * 2) ++ left;
            int pre = left;//快指针
            
            if(pre == i) ++ pre;
            if(pre > n) pre = 0;
            
            arr[i].fat = arr[pre].gra;
        }
        
        sort(arr + 1, arr + 1 + n, [&](auto &a, auto &b)
        {
            return a.id < b.id;
        });
        
        printf("Case #%d:", t);
        for(int i = 1; i <= n; ++ i)
            printf(" %d",arr[i].fat);
        printf("\n");
    }
    
    
    return 0;
}