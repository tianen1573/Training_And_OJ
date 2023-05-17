#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

struct str{
    int l, r;
    
    bool operator< (const str& t) const
    {
        return l < t.l;
        // 我觉得结合一个场景是不是能更好理解。比如，有n个人需要用教室，每个人占用教室的起始时间和终止时间是不一样的。
        // 1、如果想知道只有一间教室，能安排下的最多不冲突人数（不是所有的人都有机会，有的会被舍掉）是多少（区间选点和最大不相交问题），那么当然是最先结束的人排在前面，这样后面的人才有更多机会。如果是按左端点排序，那么如过一个人0点开始用，那么肯定他排在最前面，但是如果他自己就占用了24小时，那么只能给他一个人用了，这样就达不到最大的效果。所以按右端点排序。
        // 2、如果想知道这些人都必须安排，没有人被舍弃，至少需要多少个教室能安排下（区间分组问题）。那么肯定是按照开始时间排序，开始时间越早越优先。这样每间教室都能得到最充分的利用。
        // 这么想，是不是更好理解一些？
        // 作者：小果果
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
    
    priority_queue<int, vector<int>, greater<int> > gheap;
    
    gheap.push(arr[0].r);
    
    for(int i = 1; i < n; ++ i)
    {
        if(arr[i].l <= gheap.top())
        {
            gheap.push(arr[i].r);
        }
        else
        {
            gheap.pop();
            gheap.push(arr[i].r);
        }
    }
    
    
    cout << gheap.size();
    
    return 0;
}