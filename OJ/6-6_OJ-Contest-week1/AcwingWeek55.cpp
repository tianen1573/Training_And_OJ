#define _CRT_SECURE_NO_WARNINGS 1

/*最长连续子序列*/
/* https://www.acwing.com/problem/content/4482/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <unordered_set>
//using namespace std;
//
//unordered_set<int> b;
//int a[11];
//int n, m;
//int main()
//{
//    int tmp = 0;
//    scanf("%d%d", &n, &m);
//
//    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//    for (int i = 0; i < m; i++)
//    {
//        scanf("%d", &tmp);
//        b.insert(tmp);
//    }
//
//    for (int i = 1; i <= n; i++)
//        if (b.count(a[i])) cout << a[i] << " ";
//
//    return 0;
//}

/*倒垃圾*/
/* https://www.acwing.com/problem/content/description/4483/ */
////纯STL时间超限，需要用一个数组额外保存垃圾桶下标，减少搜索时间
////O(n + m)
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <map>
//#include <vector>
//
//using namespace std;
//
//typedef pair<bool, int> PBI;
//
//map<int, PBI> que;//坐标，标识，次数
//vector<int> ash;
//
//int n, m;
//
//int main()
//{
//    int tmp = 0;
//    scanf("%d%d", &n, &m);
//    //更新信息
//    for (int i = 0; i < n + m; i++)
//    {
//        scanf("%d", &tmp);
//        que.insert({ tmp, {false, 0} });
//    }
//    //标识垃圾桶，并保存垃圾桶下标
//    for (auto& it : que)
//    {
//        scanf("%d", &tmp);
//        if (tmp == 1)
//        {
//            it.second.first = true;
//            ash.push_back(it.first);
//        }
//    }
//    //初始左右垃圾桶和下标
//    int rig = ash[0], left = ash[0];//左右垃圾桶下标
//    int ashPos = 1, lag = 0;
//
//    for (auto it = que.begin(); it != que.end(); it++)
//    {
//        if (it->second.first == false)//居民
//        {
//            while (ashPos < ash.size() && rig < it->first) rig = ash[ashPos++];//更新右垃圾桶
//
//            //倒垃圾，绝对值代表距离，因为会出现最后全是居民，右垃圾桶无法更新的情况
//            if (abs(it->first - left) > abs(rig - it->first)) que[rig].second++;
//            else que[left].second++;
//        }
//        else //更新左垃圾桶，并打印倒垃圾数量
//        {
//            if (lag == 1) cout << que[left].second << " ";//从第二个垃圾桶开始，打印其前一个
//            left = it->first;
//            lag = 1;
//        }
//    }
//
//    //打印最后一个垃圾桶
//    auto it = que.end(); it--;
//    cout << que[left].second;
//
//    return 0;
//}