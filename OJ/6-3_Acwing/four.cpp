#define _CRT_SECURE_NO_WARNINGS 1

/*一维前缀和*/
/* https://www.acwing.com/problem/content/797/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//
//
//using namespace std;
//int n, m;
//
//vector<int> nums, sum;
//
//int main()
//{
//    int tmp;
//    cin >> n >> m;
//    nums.push_back(0); sum.push_back(0);
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> tmp;
//        nums.push_back(tmp);
//    }
//    for (int i = 1; i <= n; i++)
//        sum.push_back(sum[i - 1] + nums[i]);
//
//    while (m--)
//    {
//        int l = 0, r = 0;
//        cin >> l >> r;
//        cout << sum[r] - sum[l - 1] << endl;
//    }
//    return 0;
//}

/*二维矩阵前缀和*/
/* https://www.acwing.com/problem/content/798/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
///*仅为熟悉vector*/
////vector< vector<int> > nums;
////vector< vector<int> > sum;
////int n, m, q;
////
////int main()
////{
////    int x = 0;
////    cin >> n >> m >> q;
////    vector<int> tmp(m + 1); nums.push_back(tmp); sum.push_back(tmp);
////
////    for (int i = 1; i <= n; i++)
////    {
////        tmp.clear(); tmp.push_back(0);
////        for (int j = 1; j <= m; j++)
////        {
////            cin >> x;
////            tmp.push_back(x);
////        }
////        nums.push_back(tmp);
////    }
////
////    tmp.clear(); tmp.push_back(0);
////    for (int i = 1; i <= n; i++)
////    {
////        sum.push_back(tmp);
////        for (int j = 1; j <= m; j++)
////            sum[i].push_back(sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + nums[i][j]);
////    }
////    while (q--)
////    {
////        int x1, x2, y1, y2;
////        cin >> x1 >> y1 >> x2 >> y2;
////        cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << endl;
////    }
////    return 0;
////}
//
//const int N = 1007;
//int sum[N][N];
//int n, m, q;
//
//int main()
//{
//    cin >> n >> m >> q;
//
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            cin >> sum[i][j];
//
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
//
//    while (q--)
//    {
//        int x1, y1, x2, y2;
//        cin >> x1 >> y1 >> x2 >> y2;
//        cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << endl;
//    }
//
//
//    return 0;
//}

/*一维差分*/
/* https://www.acwing.com/problem/content/799/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int sub[100007];
//int n, m;
//
//void insert(int l, int r, int c)
//{
//    sub[l] += c;
//    sub[r + 1] -= c;
//}
//
//int main()
//{
//    int tmp = 0;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> tmp;
//        insert(i, i, tmp);
//    }
//
//    int l, r, c;
//    while (m--)
//    {
//        cin >> l >> r >> c;
//        insert(l, r, c);
//    }
//
//    for (int i = 1; i <= n; i++) sub[i] += sub[i - 1];
//
//    for (int i = 1; i <= n; i++) cout << sub[i] << " ";
//
//    return 0;
//}

/*二维差分*/
/* https://www.acwing.com/problem/content/800/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int sub[1007][1007];
//
//int n, m, q;
//
////前缀和的逆
//void insert(int x1, int y1, int x2, int y2, int val)
//{
//    sub[x1][y1] += val;
//    sub[x2 + 1][y2 + 1] += val;
//    sub[x2 + 1][y1] -= val;
//    sub[x1][y2 + 1] -= val;
//}
//
//int main()
//{
//    int tmp;
//    cin >> n >> m >> q;
//
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//        {
//            cin >> tmp;
//            insert(i, j, i, j, tmp);
//        }
//
//    int x1, y1, x2, y2, val;
//    while (q--)
//    {
//        cin >> x1 >> y1 >> x2 >> y2 >> val;
//        insert(x1, y1, x2, y2, val);
//    }
//
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            sub[i][j] += sub[i - 1][j] + sub[i][j - 1] - sub[i - 1][j - 1];
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//            cout << sub[i][j] << " ";
//        cout << endl;
//    }
//    return 0;
//}


