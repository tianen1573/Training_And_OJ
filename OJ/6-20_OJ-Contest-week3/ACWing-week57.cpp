#define _CRT_SECURE_NO_WARNINGS 1

/*57*/
/* https://www.acwing.com/activity/content/introduction/1974/ */

/*比大小*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int a, b, suma, sumb, n;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)
//        cin >> a, suma += a;
//    for (int i = 0; i < n; i++)
//        cin >> b, sumb += b;
//
//    if (suma >= sumb) cout << "Yes";
//    else cout << "No";
//
//    return 0;
//}

/*数字操作*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//
//
//
//int main()
//{
//    int n; cin >> n;
//    int res = 1, cnt = 0;//min, cnt
//    vector<int> p;
//
//    /*分解质因数*/
//    for (int i = 2; i * i <= n; i++)
//    {
//        if (n % i == 0)
//        {
//            int c = 0;
//            while (n % i == 0) n /= i, c++;//榨干
//            p.push_back(c);//次数
//            res *= i;//更新最小值
//            while ((1 << cnt) < c) cnt++;//开根号最小次数
//        }
//    }
//    if (n > 1)//判断最后的n是否为质因数
//    {
//        res *= n;
//        p.push_back(1);
//        while ((1 << cnt) < 1) cnt++;
//    }
//
//    for (auto x : p)
//    {
//        if (x < (1 << cnt))
//        {
//            cnt++;
//            break;
//        }
//    }
//
//    cout << res << " " << cnt;
//    return 0;
//}

/*最长连续子序列*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
////(a(l + 1) + ... + ar) > 100 * (r + 1 - (l + 1)) 
////->> ((a(l + 1) - 100) + ... + (ar - 100)) + 100 *(r + 1 - (l + 1)) > 100 * (r + 1 - (l + 1))
////->>((a(l + 1) - 100) + ... + (ar - 100)) > 0 
////->> sum[r] > sum[l]，则判断条件为sum[r] > sum[l]
////将前缀和简化为一个单调递减序列，则在右端点固定时，找序列中 左到右 第一个小于右端点的节点即可
////①节点前缀和比序列最小值小，需要入列，因为没有比他更小的节点，
////②若比序列最小值大，则一定存在一个下标比其小，节点值也比其小的节点，这个节点与右端点的长度一定大于它，无意义
//
//typedef long long LL;
//
//const int N = 1000010;
//
//int n;
//LL s[N];//前缀和
//int stk[N];
//
//int main()
//{
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++)
//    {
//        int x;
//        scanf("%d", &x);
//        s[i] = s[i - 1] + x - 100;//优化前缀和
//    }
//
//    int top = 0, res = 0;
//    stk[++top] = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        if (s[stk[top]] > s[i]) stk[++top] = i;//情况①
//        else if (s[stk[top]] < s[i])//情况②
//        {
//            int l = 1, r = top;
//            while (l < r)
//            {
//                int mid = l + r >> 1;
//                if (s[stk[mid]] < s[i]) r = mid;
//                else l = mid + 1;
//            }
//            res = max(res, i - stk[r]);
//            //str[r]保存的是左节点的左一个节点de下标
//            //stk[r] == (l + 1) - 1 -> i - stk[r] == i - (l + 1) + 1
//        }
//    }
//
//    printf("%d\n", res);
//    return 0;
//}

