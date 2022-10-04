#define _CRT_SECURE_NO_WARNINGS 1

/* https://www.acwing.com/activity/content/1994/ */

/*寻找1*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int n, a;
//bool lag;
//
//int main()
//{
//    cin >> n;
//    while (n--)
//    {
//        cin >> a;
//        if (a) lag = true;
//    }
//
//    if (lag) cout << "YES";
//    else cout << "NO";
//
//    return 0;
//}

/*最长子序列 -- 贪心*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//const int N = 2e5 + 11;
//int cnt, mcnt, last, cur, n;
//
// /*类似于：在一个递增序列中，求差值为1的最大长度子序列*/
//int main()
//{
//    cin >> n;
//
//    if (n == 1)
//    {
//        cout << "1";
//        return 0;//捏妈妈的，比赛的时候忘return了！
//    }
//    else
//    {
//        n--;
//        cin >> last;
//        cnt = mcnt = 1;
//    }
//
//    while (n--)
//    {
//        cin >> cur;
//
//        if (cur > 2 * last)
//        {
//            mcnt = max(mcnt, cnt);
//            cnt = 1;
//        }
//        else
//        {
//            cnt++;
//        }
//
//        last = cur;
//    }
//    mcnt = max(cnt, mcnt);
//
//    cout << mcnt;
//
//    return 0;
//}

/*染色 -- 思维*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//const int N = 1e4 + 11;
//int fat[N], clr[N], F, C, n;
//int cnt = 1;//根节点染色
//
//int main()
//{
//    cin >> n;
//    for (int i = 2; i <= n; i++)//记录父亲节点
//        cin >> F, fat[i] = F;
//    for (int i = 1; i <= n; i++)//记录节点颜色
//        cin >> C, clr[i] = C;
//
//    for (int i = 2; i <= n; i++)//
//        if (clr[i] != clr[fat[i]])//如果和父亲节点颜色不一致，则该节点需要重新染色
//            cnt++;
//
//    cout << cnt;
//    return 0;
//}