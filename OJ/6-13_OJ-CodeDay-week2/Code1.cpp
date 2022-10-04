#define _CRT_SECURE_NO_WARNINGS 1

/*单词处理器*/
/* https://www.acwing.com/problem/content/1444/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//string str[107];
//int N, K;
//
//int main()
//{
//    cin >> N >> K;
//    int curLen = 0;
//    for (int i = 1; i <= N; i++) cin >> str[i];
//
//    for (int i = 1; i <= N; )
//    {
//        if (curLen + str[i].size() <= K)//当前行长度curLen + 单词长度 <= K，输出,更新信息
//        {
//            if (curLen != 0) cout << " ";
//            cout << str[i];
//            curLen += str[i].size();
//            i++;
//        }
//        else//>= K, 换行
//        {
//            cout << endl;
//            curLen = 0;
//        }
//    }
//
//    return 0;
//}

/*三角形*/
/*https://www.acwing.com/problem/content/1673/*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//#define x first
//#define y second
//
//using namespace std;
//
//typedef pair<int, int> PII;
//PII pos[107];
//int N;
//
//int main()
//{
//    cin >> N;
//    for (int i = 1; i <= N; i++) cin >> pos[i].x >> pos[i].y;
//
//    int area = 0;
//    for (int i = 1; i <= N; i++)
//        for (int j = 1; j <= N; j++)
//            for (int k = 1; k <= N; k++)
//            {
//                if (i == j || i == k || j == k) continue;
//                /*点i模拟为直角点，j，k为两个锐角点*/
//                if ((pos[i].x == pos[j].x) && (pos[i].y == pos[k].y))
//                    area = max(area, abs((pos[i].y - pos[j].y) * (pos[i].x - pos[k].x)));
//            }
//
//    cout << area;
//}

/*社交距离*/
/* https://www.acwing.com/problem/content/1661/ */
// /*#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//
//int max_1 = 0, max_2 = 0, D = 1e5 + 11;
//string str;
//char c, hc, tc;
//int N;
//
//int main()
//{
//    cin >> N;
//    cin >> str;
//
//    int count = 0;
//    int h_len = (int)str.find('1') - 0;//第一个1的标
//    int t_len = N - 1 - (int)str.rfind('1');//最后一个1的下标
//
//    if (str.find('1') == -1)//不存在1
//    {
//        printf("%d", N - 1);
//        return 0;
//    }
//    //从第一个 1 到 最后一个 1，记录最大区间max_1，次大区间max_2，最小间隔D
//    for (int i = (int)str.find('1') + 1; i <= (int)str.rfind('1'); i++)//从第一个1的后一位开始，避免D初始为0
//    {
//        if (str[i] == '0') count++;
//        else
//        {
//            if (count + 1 >= max_1)
//            {
//                max_2 = max_1;
//                max_1 = count + 1;
//            }
//            else if (count + 1 > max_2) max_2 = count + 1;
//
//            D = min(D, count + 1);
//            count = 0;
//        }
//    }
//
//    int d = 0;//记录插入后的最大新区间间隔
//
//    d = max(d, max_1 / 3);//2个牛插到一个区间
//    d = max(d, max_2 / 2);//插到两个区间
//
//    if (h_len && t_len)//若头尾都没牛，插到队头队尾
//    {
//        d = max(d, min(h_len, t_len));
//    }
//    if (h_len)//插到队头
//    {
//        int  max_11 = max(max_1, h_len);//更新最大区间
//        d = max(d, min(h_len, max_11 / 2));
//    }
//    if (t_len)//插到队尾
//    {
//        int max_11 = max(max_1, t_len);
//        d = max(d, min(t_len, max_11 / 2));
//    }
//
//    D = min(D, d);//更新最小间隔
//    cout << D;
//
//    return 0;
//}*/
//
// /*y总*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 100010;
//
//int n, m;
//char str[N];
//int p[N];
//
//int main()
//{
//    scanf("%d%s", &n, str + 1);
//    for (int i = 1; i <= n; i++)
//        if (str[i] == '1')
//            p[++m] = i;
//
//    if (!m) printf("%d\n", n - 1);
//    else
//    {
//        int xmin = N;
//        for (int i = 1; i < m; i++)
//            xmin = min(xmin, p[i + 1] - p[i]);
//
//        int y = max((p[1] - 1) / 2, (n - p[m]) / 2);
//        for (int i = 1; i < m; i++)
//            y = max(y, (p[i + 1] - p[i]) / 3);
//
//        int y1 = p[1] - 1, y2 = n - p[m];
//        if (y1 < y2) swap(y1, y2);
//        for (int i = 1; i < m; i++)
//        {
//            int d = (p[i + 1] - p[i]) / 2;
//            if (d >= y1) y2 = y1, y1 = d;
//            else if (d > y2) y2 = d;
//        }
//        printf("%d\n", min(xmin, max(y, y2)));
//    }
//
//    return 0;
//}

/*混合牛奶*/
/* https://www.acwing.com/problem/content/1716/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int c[3], m[3];
//
//int main()
//{
//    for (int i = 0; i < 3; i++)
//        cin >> c[i] >> m[i];
//
//    for (int i = 0; i < 100; i++)
//    {
//        int a = i % 3, b = (i + 1) % 3;
//        int ml = min(m[a], c[b] - m[b]);
//        m[a] -= ml, m[b] += ml;
//    }
//
//    cout << m[0] << endl;
//    cout << m[1] << endl;
//    cout << m[2] << endl;
//
//    return 0;
//}

/*果壳游戏*/
/* https://www.acwing.com/problem/content/1697/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
///* 模拟：O(m * n) */
//int ans[3][4];
//
//int n;
//
//int main()
//{
//
//    ans[0][1] = ans[1][2] = ans[2][3] = 1;//初始化第 1，2，3 坚果壳下有石头
//    cin >> n;
//
//    while (n--) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        for (int i = 0; i < 3; i++)
//        {
//            swap(ans[i][a], ans[i][b]);
//            if (ans[i][c]) ans[i][0]++;
//        }
//    }
//
//    int Ans = max(ans[0][0], max(ans[1][0], ans[2][0]));
//
//    cout << Ans;
//
//    return 0;
//}
// /*优化：O(n), 三合一，三个不同位置坚果，同一种操作，则坚果位置不会重叠，直接找猜测位置下是哪一个坚果
//int n, x[4], ans[4];
//int main()
//{
//    for (int i = 1; i <= 3; i++) x[i] = i;
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//        swap(x[a], x[b]);
//        ans[x[c]]++;
//    }
//    cout << max({ans[1], ans[2], ans[3]});
//    return 0;
//}*/
