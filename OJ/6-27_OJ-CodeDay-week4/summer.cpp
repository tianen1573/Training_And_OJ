#define _CRT_SECURE_NO_WARNINGS 1

/*行程排序*/
/* https://www.acwing.com/problem/content/695/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <set>
//#include <unordered_map>
//
//using namespace std;
//
//#define x first
//#define y second
//
//typedef unordered_map<string, string> UMSS;
//
//const int N = 10011;
//
//int T, n;
//
//int main()
//{
//    cin >> T;
//    for (int t = 1; t <= T; t++)
//    {
//        UMSS um;//记录节点
//        set<string> in;//记录入度
//        string a, b;
//
//        cin >> n;
//        for (int i = 1; i <= n; i++)
//        {
//            cin >> a >> b;
//            um[a] = b;
//            //um.insert({ a, b });
//            in.insert(b);
//        }
// 
//        /*找头*/
//        string hh;
//        for (auto h : um)
//            if (in.find(h.first) == in.end())
//            {
//                hh = h.first;
//                break;
//            }
//
//    
//        printf("Case #%d: ", t);
//
//        /*遍历*/
//        for (; um.find(hh) != um.end(); hh = um[hh])
//            cout << hh << '-' << um[hh] << ' ';
//
//        cout << endl;
//
//    }
//
//    return 0;
//}

/*放苹果*/
/* https://www.acwing.com/problem/content/description/3431/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//
//// int sum, ans;
//// int n, m;
//
//// //若有空盘子，前面的盘子会空，后面的不会
//// void dfs(int step, int num)
//// {
////     if(step == n)//
////     {
////         if(m - sum >= num) ans++;
////         return;
////     }
////     for(int j = num; j <= m - sum; j++)
////     {
////         sum += j;
////         dfs(step + 1, j);
////         sum -= j;
////     }
//// }
//
//// int main()
//// {
////     while(~scanf("%d%d", &m, &n))
////     {
////         sum = ans = 0;
////         dfs(1, 0);
////         cout << ans << endl;
////     }
//
//
////     return 0;
//// }
//
//
//const int N = 12;
//
//int m, n;
//int f[N][N]; // f[m][n] 表示把 m 个同样的苹果放在 n 个同样的盘子里的分法数
//
//int main()
//{
//    for (int i = 0; i < N; i++) f[i][1] = 1; // 把 i 个苹果放在 1 个盘子里，只有 1 种方案
//    for (int i = 0; i < N; i++) f[0][i] = 1; // 把 0 个苹果放在 i 个盘子里，也只有 1 种方案
//
//    for (int i = 1; i < N; i++) // 枚举苹果数
//        for (int j = 2; j < N; j++) // 枚举盘子数
//            if (i < j) f[i][j] = f[i][i]; // 如果苹果数 < 盘子数，则必定有 (盘子数 - 苹果数) 个空着的盘子，可以将这些空着的盘子去掉
//            else f[i][j] = f[i][j - 1] + f[i - j][j]; // 苹果数 ≥ 盘子数，分两种情况讨论，可以有一个盘子空着，也可以每个盘子至少放 1 个
//
//    while (cin >> m >> n) cout << f[m][n] << '\n';
//
//    return 0;
//}

/*简单排序*/
/* https://www.acwing.com/problem/content/description/3480/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//const int N = 1007;
//
//vector<int> p;
//bool t[N];
//int n;
//
//int main()
//{
//    cin >> n;
//
//    int a;
//    // for (int i = 0; i < n; i ++ )
//    //     cin >> a, p.push_back(a);
//
//    // sort(p.begin(), p.end());
//
//    // p.erase(unique(p.begin(), p.end()), p.end());
//
//    // for(auto x : p)
//    //     cout << x << ' ';
//
//    //桶排序
//    for (int i = 1; i <= n; i++)
//        cin >> a, t[a] = true;
//    for (int i = 1; i <= N; i++)
//        if (t[i]) cout << i << ' ';
//
//
//    return 0;
//}

/*哈夫曼树*/
/* https://www.acwing.com/problem/content/description/3534/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
////哈夫曼的带权路径长度为 节点两两结合的和 的 和
//
//const int N = 1009;
//
//vector<int> p;
//int sum, Sum;
//int a, n;
//
//int cmp(int a, int b)
//{
//    return a > b;
//}
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)  cin >> a, p.push_back(a);
//    sort(p.begin(), p.end(), cmp);
//
//    while (p.size() > 1)//最后一个为根节点，长度为0
//    {
//        sum = p[p.size() - 1] + p[p.size() - 2];
//        Sum += sum;
//
//        p.pop_back(), p.pop_back();
//
//        p.push_back(sum);
//        sort(p.begin(), p.end(), cmp);
//    }
//
//
//    cout << Sum;
//    return 0;
//}

/*数值转换*/
/* https://www.acwing.com/problem/content/3441/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//char num[16] = { '0', '1', '2', '3', '4', '5','6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
//int a, b;
//string n;
//string m;
//
//int sum, rem, quo;
//
//int main()
//{
//    cin >> a >> n >> b;
//
//    //转换成十进制
//    for (int i = 0; i < n.size(); i++)
//    {
//        if (n[i] >= 'a')
//            sum = sum * a + (n[i] - 'a' + 10);
//        else if (n[i] >= 'A')
//            sum = sum * a + (n[i] - 'A' + 10);
//        else
//            sum = sum * a + (n[i] - '0');
//    }
//    //存余-转换成b进制
//    while (sum)
//    {
//        m += num[sum % b];
//        sum /= b;
//    }
//
//    //逆置
//    reverse(m.begin(), m.end());
//
//
//    cout << m;
//
//    return 0;
//}

/*倒水问题*/
/* https://www.acwing.com/problem/content/3514/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <unordered_set>
//
//using namespace std;
//
//const long long X = 10000;
//unordered_set <int> ans;//C的状态
//unordered_set <long long> wat;//ACB的状态
//int C[3];
//
//long long getVal(int c[])
//{
//    return c[2] * X * X + c[1] * X + c[0];
//}
//void pour(int t[], int i, int j)
//{
//    int v = min(t[i], C[j] - t[j]);
//    t[i] -= v, t[j] += v;
//}
//void dfs(int c[])
//{
//    ans.insert(c[2]); wat.insert(getVal(c));
//
//    int t[3];//递归时：定义一个重置内容 内存需要小于 初始化赋值
//    for (int i = 0; i < 3; i++)
//        for (int j = 0; j < 3; j++)
//            if (i != j)
//            {
//                memcpy(t, c, sizeof(t));
//                pour(t, i, j);
//                if (!wat.count(getVal(t)))//该状态未出现，递归
//                    dfs(t);
//            }
//}
//
//int main()
//{
//    while (cin >> C[0] >> C[1] >> C[2])
//    {
//        ans.clear(); wat.clear();
//        int c[3] = { 0, 0, C[2] };//水的体积， C：容量
//        dfs(c);
//        cout << ans.size() << endl;
//    }
//
//    return 0;
//}