#define _CRT_SECURE_NO_WARNINGS 1

/*Acwing-week-59*/
/* https://www.acwing.com/activity/content/2015/ */

/*数组操作*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int sum[109] = { 0 }, SUM = 0, Min = 99999;
//int n;
//
//int main()
//{
//    cin >> n;
//    int tmp;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> tmp;
//        sum[i] = sum[i - 1] + tmp;//前缀和
//        Min = min(Min, sum[i]);//最小前缀和
//        SUM += tmp;//数组和
//    }
//    Min = min(Min, 0);//特判
//    cout << SUM - Min;
//    return 0;
//}

/*减法操作*/
////每次减去最小质因数，减的过程中，因数发生改变，最小质因数也会改变；
////但最小的质数为2，如果存在因数为2，则最小质因数一直为2，则：
////若n为素数，只需减一次
////若n为偶数，每次都减2，共 n / 2 次
////若n为奇数，则最小质因数一定为奇数，减去它，变为偶数， 共 （n - d）/ 2 + 1 次
//
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <math.h>
//
//using namespace std;
//
//typedef long long LL;
//
//LL Mind, n, cnt = 0;
//
//bool prime(LL p)//快速判断素数
//{
//    if (p == 2 || p == 3)
//    {
//        return true;
//    }
//    if (p % 6 != 1 && p % 6 != 5)
//    {
//        return false;
//    }
//    for (int i = 5; i <= floor(sqrt(p)); i += 6)
//    {
//        if (p % i == 0 || p % (i + 2) == 0)
//        {
//            return false;
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    cin >> n;
//
//    if (prime(n))//素数
//    {
//        cout << "1";
//        return 0;
//    }
//
//    if (n % 2)//奇数
//    {
//        for (Mind = 3; Mind <= n; Mind += 2)
//            if (n % Mind == 0)
//            {
//                cnt++;
//                n -= Mind;
//                break;
//            }
//    }
//
//    cnt += (n / 2);
//    cout << cnt;
//    return 0;
//}

/*环形联通分量*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//const int N = 2e5 + 7;
//
//bool s[N];//状态
//short b[N];//出入度
//vector<int> map[N];//
//
//int n, m;
//int cnt;
//bool flag;
//
//void dfs(int i)
//{
//    s[i] = true;
//    for (auto x : map[i])
//    {
//        if (s[x]) continue;
//        if (b[x] != 2) flag = false;
//        dfs(x);
//    }
//}
//
//int main()
//{
//    cin >> n >> m;
//    int x, y;
//    while (m--)
//    {
//        scanf("%d %d", &x, &y);
//
//        map[x].push_back(y);
//        map[y].push_back(x);
//
//        b[x]++; b[y]++;
//    }
//
//    for (int i = 1; i <= n; i++)
//    {
//        if (s[i] || b[i] != 2) continue;
//        flag = true;
//        dfs(i);
//        if (flag) cnt++;
//    }
//
//    cout << cnt;
//
//    return 0;
//}