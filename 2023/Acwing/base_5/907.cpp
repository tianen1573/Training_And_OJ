#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

struct str{
    int l, r;
    
    bool operator< (const str& t)const
    {
        return l < t.l;
    }
}arr[N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int start, end;
    cin >> start >> end >> n;
    for(int i = 0; i < n; ++ i) cin >> arr[i].l >> arr[i].r;
    sort(arr, arr + n);
    
    int cnt = 0;
    bool flag = false;
    for(int i = 0; i < n; ++ i)
    {
        //求是否有区间能覆盖start
        int j = i, rig = -2e9;
        while(j < n && arr[j].l <= start)
        {
            rig = max(rig, arr[j].r);
            ++ j;
        }
        
        //没有区间能覆盖start
        if(rig < start)
        {
            cnt == -1;
            break;
        }
        //有区间能覆盖start
        cnt ++;
        
        //并且直接能结束
        if(rig >= end)
        {
            flag = true;
            break;
        }
        
        //更新待覆盖区间左节点
        start = rig;
        i = j - 1;
        
    }
    
    if(!flag) cnt = -1;
    cout << cnt;
    
    return 0;
}