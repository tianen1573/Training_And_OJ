#define _CRT_SECURE_NO_WARNINGS 1

/*NewOJ-Week9*/
/* http://oj.ecustacm.cn/contest.php?cid=1024 */


/*A. 平均数组*/
//#include<stdlib.h>
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int T, N, X;
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> N >> X;
//
//		if (N % 2 == 1)
//		{
//			cout << X << " ";
//			for (int i = 1, j = 1; i < N; i+=2,j++)
//		{
//				cout << X - j << " " << X + j << " ";
//		}
//		}
//		else
//		{
//			for (int i = 0, j = 1; i < N; i += 2, j++)
//			{
//				cout << X - j << " " << X + j << " ";
//			}
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

/*B. 配对*/
//#include<stdlib.h>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int maxn = 2e4 + 3;
//
//int a[maxn], b[maxn];
//int N;
//int main()
//{
//	int T = 0;
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		int MAX = 0;
//		
//		cin >> N;
//		for (int i = 0; i < N; i++)
//			cin >> a[i];
//		for (int i = 0; i < N; i++)
//			cin >> b[i];
//		
//		sort(a, a + N);
//		sort(b, b + N);
//
//		for (int i = 0; i < N; i++)
//			MAX = max(MAX, a[i] + b[N - 1 - i]);
//
//		cout << MAX << endl;
//	}
//
//	return 0;
//}

/*C. 可逆循环字符串*/
//#include<stdlib.h>
//#include<iostream>
//#include<algorithm>
//#include<string.h>
//using namespace std;
//
//int main()
//{
//	int T = 0;
//	cin >> T;
//	for (int i = 1; i <= T; i++)
//	{
//		string s;
//		cin >> s;
//		string ss = s + s;
//		reverse(s.begin(), s.end());
//		cout << (ss.find(s) == -1 ? 0 : 1) << endl;
//	}
//
//	return 0;
//}

/*跳房子游戏 -- 89% */
//#include <iostream>
//#include <algorithm>
//#include <tuple>
//#include <math.h>
//#include <vector>
//
//using namespace std;
//
//typedef long long LL;
//
//const int N = 507;
//
//int n, K;
////vector< vector<int> > g(N, vector<int>(N));//存元素
//vector< tuple<int, int, int> > vec;//存数据
//
//LL getDist(LL x1, LL x2, LL y1, LL y2)
//{
//	return min((x1 - x2) * (x1 - x2), (y1 - y2) * (y1 - y2));
//}
//
//int main()
//{
//	int tmp;
//	cin >> n >> K;
//	for(int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//		{
//			cin >> tmp;
//			vec.emplace_back( tmp, i, j );
//		}
//	sort(vec.begin(), vec.end());
//
//	int cur = 0;
//	vector<LL> ans;
//	vector< pair<int, int> > pos;
//	for (; cur <= vec.size(); cur++)
//	{
//		auto v = get<0>(vec[cur]);
//		if (v == 1)
//		{
//			ans.push_back(0);
//			pos.push_back({ get<1>(vec[cur]), get<2>(vec[cur]) });
//		}
//		else break;
//	}
//
//	for (int  v = 2; v <= K; v++)
//	{
//		vector<LL> tans;
//		vector< pair<int, int> > tpos;
//
//		for (; cur < vec.size(); cur++)
//		{
//			auto vv = get<0>(vec[cur]);
//			if (vv - v > 1)
//			{
//				cout << "-1";
//				return 0;
//			}
//			else if (vv != v) break;
//
//			LL dis = 1e18 + 7;
//			for (int i = 0; i < ans.size(); i++)
//				dis = min(dis, ans[i] + getDist(get<1>(vec[cur]), pos[i].first, get<2>(vec[cur]), pos[i].second));
//
//			tans.push_back(dis);
//			tpos.push_back({ get<1>(vec[cur]), get<2>(vec[cur]) });
//		}
//
//		ans = tans, pos = tpos;
//	}
//
//	LL res = 1e18 + 11;
//	for (int i = 0; i < ans.size(); i++)
//		res = min(res, ans[i]);
//
//	cout << res;
//
//	return 0;
//}