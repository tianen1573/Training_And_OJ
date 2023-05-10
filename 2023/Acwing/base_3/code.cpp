

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

namespace 稠密图
{
    using namespace std;

    const int N = 1010;

    int g[N][N], dist[N];
    bool st[N];

    int n;

    int dijkstra()
    {
        //0. 初始化源点到每个点的最短距离为正无穷
        memset(dist, 0x3f, sizeof dist);
        //0. 初始化源点到源点距离为0
        dist[1] = 0;

        //n次遍历
        for (int i = 0; i <= n; ++i)
        {
            //1. 从还未确认最短距离的点集中， 找到最短距离的点
            int t = -1;
            for (int j = 1; j <= n; ++j)
            {
                if (!st[j] && (t == -1 || dist[j] < dist[t]))
                    t = j;
            }

            // if(t == n) break;

            //2. 将其添加到确定最短距离的点集中 -- 走到这一步，源点到该点的最短距离已经确定
            st[t] = true;

            //3.通过这个点， 更新源点到其他点的临时最短距离
            for (int j = 1; j <= n; ++j)
            {
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }

        //是否能到达
        if (dist[n] == 0x3f3f3f3f)
            return -1;
        else
            return dist[n];
    }
}


namespace 稀疏图
{

}