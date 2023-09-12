//小红正在做一个计划，她先写了份初版方案，但是领导不太满意，让小红改一改。
// 改着改着，小红就改了16版方案，然后领导说，还是用初版方案吧，现在小红非常的......
// 小红组内有n个人，大家合作完成了一个初版方案，初始时大家的愤怒值都是0。
// 但是领导对方案并不满意，共需要修改m次方案，每次修改会先让第l到第r个人的愤怒值加1，然后再修改方案。
// 组内每个人都有一个愤怒阈值a，—旦第i次修改时有人愤怒值大于愤怒阈值，
// 他就会去找领导对线，直接将最终的方案定为第i―1方案，并且接下来方案都不需要再修改了。
// 小红想知道，最终会使用第几版方案。初版方案被认为是第0版方案。
// 第一行输入两个整数n, m(1 ≤ n, m ≤ 10^5)表示数组长度和修改次数。
// 第二行输入n个整数表示数组a(0 ≤ ai ≤ 10^9)。
// 接下来m行，每行输入两个整数l, r(1 < l ≤ r ≤ n)。


#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int tar[100001], sub[100001], arr[100001][2];

bool func(int cnt, int n)
{
    memset(sub, 0, 100001 * 4);
    for(int i = 1; i <= cnt; ++ i)
    {
        // int l = arr[i][0], r = arr[i][1];
        ++ sub[arr[i][0]];
        -- sub[arr[i][1] + 1];
    }
    for(int i = 1; i <= n; ++ i)
    {
        sub[i] += sub[i - 1];
        if(sub[i] > tar[i])
            return true;
    }

    return false;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)
        cin >> tar[i];
    for(int i = 1; i <= m; ++ i)
        cin >> arr[i][0] >> arr[i][1];

    int l = 1, r = m;
    while(l < r)
    {
        int mid = (l + r) >> 1;

        if(func(mid, n))
            r = mid;
        else
            l = mid + 1;
    } 
    
    if(l == m) ++ l;
    cout << l - 1 << endl;

    return 0;
}