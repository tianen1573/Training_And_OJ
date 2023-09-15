// 牛牛组织了一场拉力赛，在—条水平的赛道上，共有n辆赛车，
// 在当前时刻，牛牛记录下来了从左到右每辆车的位置p1, p2,.. .pn(0≤p1<p2< ...<Pn)，
// 假设起点处位置为0，因此它们当前的排名依次为: n, n - 1,n-2,...,1。
// 现在牛牛知道在位置p;处的车辆速度为vi，假设所有的车保持匀速行驶，牛牛想知道在t个单位时间后，有多少赛车的排名上升了?
// 注:如果在t个单位时间后有两辆车的位置相同，则这两辆车的排名相同。一辆车的排名为在它前面的车辆的个数加1。


#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long LL;

int main()
{
    int n, t;
    cin >> n >> t;
    
    vector<LL> v(n + 1, 0);
    vector<vector<LL>> p(n + 1, vector<LL>(2, 0));
    for(int i = 1; i <= n; ++ i)
    {
        p[i][0] = n - i + 1;
        cin >> p[i][1];
//         cout << p[i][0] << ' ' << p[i][1] << endl;
    }
    
    for(int i = 1; i <= n; ++ i)
    {
        cin >> v[i];
    }
    for(int i = 1; i <= n; ++ i)
    {
        p[i][1] += v[i] * t;
//         cout << p[i][0] << ' ' << p[i][1] << endl;
    }
    sort(p.begin() + 1, p.end(), [&](auto& a, auto& b)
         {
             return a[1] > b[1];
         });
    LL lastP = -1, lastV = -1;
    int ans = 0;
    for(int i = 1; i <= n; ++ i)
    {
//         cout << p[i][0] << ' ' << p[i][1] << '|';
        if(p[i][1] == lastP)
        {
            p[i][1] = lastV;
        }
        else
        {
            lastP = p[i][1];
            p[i][1] = i;
            lastV = i;
        }
        
//         cout << p[i][0] << ' ' << p[i][1] << endl;
        if(p[i][0] > p[i][1])
            ans ++;
    }
    
    cout << ans;
    return 0;
}