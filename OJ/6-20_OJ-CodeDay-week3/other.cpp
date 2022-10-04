#define _CRT_SECURE_NO_WARNINGS 1

/*困牛放牧*/
/* https://www.acwing.com/problem/content/1685/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int pos[4];
//
//int main()
//{
//    int Min, Max;
//    cin >> pos[1] >> pos[2] >> pos[3];
//
//    sort(pos + 1, pos + 4);
//
//    if ((pos[1] + 1 == pos[2]) && (pos[2] + 1 == pos[3])) Min = 0;//abc
//    else if (pos[2] - pos[1] == 2 || pos[3] - pos[2] == 2) Min = 1;//a-b~c || a~b-c
//    else Min = 2;//a~b~c
//
//    Max = max((pos[2] - pos[1]), pos[3] - pos[2]) - 1;//最大间隔
//
//    cout << Min << endl << Max;
//
//}

/*水桶传递序列*/
/* https://www.acwing.com/problem/content/1472/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int ans;
//int Rx, Ry, Lx, Ly, Bx, By;
//
//
//int main()
//{
//    char c;
//    for (int i = 1; i <= 10; i++)
//    {
//
//        for (int j = 1; j <= 10; j++)
//        {
//            cin >> c;
//            if (c == 'B') Bx = i, By = j;
//            else if (c == 'L') Lx = i, Ly = j;
//            else if (c == 'R') Rx = i, Ry = j;
//        }
//    }
//    ans = abs(Lx - Bx) + abs(Ly - By) - 1;
//
//    /*判断是否在一条直线上，且R在中间*/
//    if ((Lx == Bx && Bx == Rx && (Ry - By) * (Ry - Ly) < 0)
//        || (Ly == By && By == Ry && (Rx - Bx) * (Rx - Lx) < 0))
//        ans += 2;
//
//    cout << ans;
//
//    return 0;
//}

/*阻挡广告牌*/
/* https://www.acwing.com/problem/content/1763/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//struct ans
//{
//    int x1, y1, x2, y2;
//    int area()
//    {
//        return (y2 - y1) * (x2 - x1);
//    }
//}a, b, t;
//
//int Coverage(ans p, ans q)
//{
//    /*左边取大x，右边取小x；上边取小y，下边取大y, 不重合则为负*/
//    int X = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
//    int Y = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
//
//    return X * Y;
//}
//
//int main()
//{
//
//    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
//    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
//    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
//
//    int area = a.area() + b.area() - Coverage(a, t) - Coverage(b, t);
//
//    cout << area;
//
//
//    return 0;
//}

/*阻挡广告牌Ⅱ*/
/* https://www.acwing.com/problem/content/1751/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//struct ans
//{
//    int x1, y1, x2, y2;
//    int area()
//    {
//        return (y2 - y1) * (x2 - x1);
//    }
//}a, t;
//
//int main()
//{
//    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
//    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
//
//    /*当且仅当，饲料牌遮挡除草机牌后，除草机牌仍为4个直角才满足*/
//    //左右遮挡
//    if (a.y2 >= t.y2 && a.y1 <= t.y1 && !(t.x2 > a.x2 && t.x1 < a.x1))
//    {
//        int X = max(0, min(a.x2, t.x2) - max(a.x1, t.x1));
//        cout << t.area() - (X * (t.y2 - t.y1));
//        return 0;
//    }
//    //上下遮挡
//    if (a.x2 >= t.x2 && a.x1 <= t.x1 && !(t.y2 > a.y2 && t.y1 < a.y1))
//    {
//        int Y = max(0, min(a.y2, t.y2) - max(a.y1, t.y1));
//        cout << t.area() - (Y * (t.x2 - t.x1));
//        return 0;
//    }
//
//    cout << t.area();
//
//    return 0;
//}

/*传送*/
/* https://www.acwing.com/problem/content/1739/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int a, b;;
//int x, y;
//
//int main()
//{
//    cin >> a >> b >> x >> y;
//
//    if (a > b) swap(a, b);
//    if (x > y) swap(x, y);
//
//    int dis = min(b - a, abs(x - a) + abs(y - b));
//
//    cout << dis;
//
//    return 0;
//}

/*组队井字游戏*/
/* https://www.acwing.com/problem/content/description/1727/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <set>
//#include <vector>
//using namespace std;
// /*1. 模拟 
// 2. 集合set去重 */
//
//set<set<char>> ans[2];
//string g[3];
//
//void insert(vector<vector<int>> ps)
//{
//    set<char> S;
//    for (auto& p : ps)
//    {
//        int x = p[0], y = p[1];
//        S.insert(g[x][y]);
//    }
//
//    if (S.size() == 1) ans[0].insert(S);
//    else if (S.size() == 2) ans[1].insert(S);
//}
//
//int main()
//{
//    for (int i = 0; i < 3; i++) cin >> g[i];
//
//    for (int i = 0; i < 3; i++) insert({ {i, 0}, {i, 1}, {i, 2} });//行
//    for (int i = 0; i < 3; i++) insert({ {0, i}, {1, i}, {2, i} });//列
//    insert({ {0, 0}, {1, 1}, {2, 2} });//对角线
//    insert({ {2, 0}, {1, 1}, {0, 2} });//对角线
//
//    cout << ans[0].size() << endl;
//    cout << ans[1].size() << endl;
//    return 0;
//}