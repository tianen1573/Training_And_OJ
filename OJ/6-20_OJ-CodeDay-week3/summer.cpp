#define _CRT_SECURE_NO_WARNINGS 1

/*擅长C*/
/* https://www.acwing.com/problem/content/description/4279/ */
//#include <iostream>
//#include <string>
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//string ch[185];//存抽象
//string str;//句子
//string word[8];//待输出单词的每一行
//int pos[10];//单词相对于A的位置
//
//
//int main()
//{
//    int lag = 0;//标识是否有单词已输出
//
//    for (int i = 1; i <= 182; i++) cin >> ch[i];
//
//    getchar();
//    getline(cin, str);//读取空格
//
//    for (int i = 0; i < str.size(); i++)
//    {
//        int j = i;
//        for (; j < str.size(); j++)
//            if (str[j] > 'Z' || str[j] < 'A') break;
//            else pos[j - i] = str[j] - 'A';
//
//        if (j == i) continue;//不是单词就跳过
//
//        if (lag) cout << endl;
//        lag = 1;
//
//        for (int k = 0; k < j - i; k++)
//        {
//            word[1] += ch[pos[k] * 7 + 1] + ' ';
//            word[2] += ch[pos[k] * 7 + 2] + ' ';
//            word[3] += ch[pos[k] * 7 + 3] + ' ';
//            word[4] += ch[pos[k] * 7 + 4] + ' ';
//            word[5] += ch[pos[k] * 7 + 5] + ' ';
//            word[6] += ch[pos[k] * 7 + 6] + ' ';
//            word[7] += ch[pos[k] * 7 + 7] + ' ';
//        }
//        for (int k = 1; k <= 7; k++)
//        {
//            cout << word[k] << endl;
//            word[k] = word[0];//清空
//        }
//
//
//        i = j;
//    }
//
//
//    return 0;
//}

/*区块反转*/
/* https://www.acwing.com/problem/content/4280/ */
//#include<vector>
//#include<iostream>
//#include<algorithm>
//
//#define x first
//#define y second
//
//using namespace std;
//
//const int N = 100011;
//
//int val[N], ne[N];//哈希表存关键值和下一节点
//vector< pair<int, int> > tmp, ans;
//int n, K, head;
//
//int main()
//{
//    cin >> head >> n >> K;
//
//    int addr, data, next;
//    while (n--)
//    {
//        scanf("%d%d%d", &addr, &data, &next);
//        val[addr] = data, ne[addr] = next;
//    }
//
//    for (int i = head; i != -1; i = ne[i]) tmp.push_back({ i, val[i] });//建立链表
//
//    int ans_size = tmp.size();
//
//    if (ans_size % K)//先存最后多出的 小于K个节点
//        for (int i = ans_size % K; i >= 1; i--)
//            ans.push_back({ tmp[ans_size - i].x, tmp[ans_size - i].y });
//
//    for (int i = ans_size - ans_size % K; i >= 1; i -= K)
//    {
//        for (int j = K; j >= 1; j--)
//            ans.push_back({ tmp[i - j].x, tmp[i - j].y });
//    }
//
//    for (int i = 0; i < ans.size(); i++)
//    {
//        printf("%05d %d ", ans[i].x, ans[i].y);
//        if (i + 1 < ans.size()) printf("%05d\n", ans[i + 1].x);
//        else printf("-1");
//    }
//
//
//    return 0;
//}

/*峰会*/
/* https://www.acwing.com/problem/content/description/4281/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//const int N = 209;
//
//bool g[N][N];
//int que[N];
//int n, m, k, l;
//
//int main()
//{
//    cin >> n >> m;
//
//    int a, b;
//    while (m--)
//    {
//        cin >> a >> b;
//        g[a][b] = g[b][a] = true;
//    }
//
//    cin >> k;
//    for (int K = 1; K <= k; K++)
//    {
//        cin >> l;
//        for (int i = 1; i <= l; i++) cin >> que[i];
//
//        /*是否两两认识*/
//        for (int i = 1; i <= l; i++)
//            for (int j = i + 1; j <= l; j++)
//                if (!g[que[i]][que[j]])
//                {
//                    printf("Area %d needs help.\n", K);
//                    goto next;
//                }
//        /*是否缺人*/
//        for (int i = 1; i <= n; i++)
//        {
//            int j = 1;
//            for (j = 1; j <= l; j++)
//                if (!g[i][que[j]]) break;
//            if (j == l + 1)
//            {
//                printf("Area %d may invite more people, such as %d.\n", K, i);
//                goto next;
//            }
//        }
//        /*不多不少*/
//        printf("Area %d is OK.\n", K);
//
//    next:
//        ;
//    }
//    return 0;
//
//}


/* 笛卡尔树 */
/* https://www.acwing.com/problem/content/4282/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//struct Node
//{
//    int l, r;
//}tree[37];//存左右孩子下标
//
//int q[37];
//int n;
//
//int get_minPos(int l, int r)
//{
//    int minv = q[l], pos = l;
//    for (int i = l; i < r; i++)
//        if (minv > q[i])
//            minv = q[i], pos = i;
//
//    return pos;
//}
//
//int dfs(int l, int r)
//{
//    if (l >= r) return -1;
//
//    int pos = get_minPos(l, r);//区间最小值下标
//
//    tree[pos] = { dfs(l, pos), dfs(pos + 1, r) };
//
//    return pos;
//}
//void print()
//{
//    int root = get_minPos(0, n);//根节点
//    queue<int> que;
//    que.push(root);
//
//    while (!que.empty())//bfs
//    {
//        int h = que.front();
//        cout << q[h] << " ";
//
//        if (~tree[h].l) que.push(tree[h].l);
//        if (~tree[h].r) que.push(tree[h].r);
//
//        que.pop();
//    }
//}
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> q[i];
//
//    dfs(0, n);
//    print();
//
//    return 0;
//}

/*立方体Ⅳ*/
/* https://www.acwing.com/problem/content/description/693/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1007;
//
//int g[N * N][2];//记录下标
//
//int val, maxCnt;//最大值
//int cnt, tval;//当前值
//
//int T, s;
//
//int main()
//{
//    cin >> T;
//
//    for (int t = 1; t <= T; t++)
//    {
//        //初始：最初胜者为1号房间，步数为1
//        tval = 1, val = 1, maxCnt = 1, cnt = 1;
//
//        cin >> s;
//        int tmp;
//        for (int i = 1; i <= s; i++)
//            for (int j = 1; j <= s; j++)
//                cin >> tmp, g[tmp][0] = i, g[tmp][1] = j;//记录下标
//
//        for (int i = 2; i <= s * s; i++)
//        {
//            if (abs(g[i][0] - g[i - 1][0]) + abs(g[i][1] - g[i - 1][1]) == 1)//连续的数 且 位置相连
//            {
//                cnt++;
//                if (cnt > maxCnt)//更新
//                {
//                    maxCnt = cnt;
//                    val = tval;
//                }
//            }
//            else//连续的数 但 位置不相连
//            {
//                cnt = 1;//更新临时房间的步数
//                tval = i;//以断点房间为起点
//            }
//        }
//
//        cout << "Case #" << t << ": " << val << ' ' << maxCnt << endl;
//    }
//
//    return 0;
//}

/*最长算数*/
/* https://www.acwing.com/problem/content/3314/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//const int N = 2e5 + 7;
//
//int T, n;
//
//int main()
//{
//    cin >> T;
//    for (int t = 1; t <= T; t++)
//    {
//        cin >> n;
//
//        //初始两个数据
//        int a, b;
//        cin >> a >> b;
//
//        //初始： 差值， 最大连续， 当前连续
//        int sub = b - a, maxCnt = 2, cnt = 2;
//
//        n -= 2;
//        while (n--)
//        {
//            cin >> a;
//            if (a - b == sub) maxCnt = max(++cnt, maxCnt);//满足条件
//            else
//            {
//                cnt = 2;
//                sub = a - b;
//            }
//            b = a;//更新减数
//        }
//
//        cout << "Case #" << t << ": " << maxCnt << endl;
//    }
//
//    return 0;
//}
