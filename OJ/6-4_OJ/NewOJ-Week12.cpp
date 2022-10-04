#define _CRT_SECURE_NO_WARNINGS 1

/*NewOJ-week12*/
/* http://oj.ecustacm.cn/contest.php?cid=1030 */

/*A. Ö½ÅÆÓÎÏ·*/
/*Ä£Äâ-sort*/
//#include<iostream>
//#include<stdlib.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int n = 0, tmp = 0;
//	long long sum = 0;
//	vector<int> nums;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> tmp;
//		nums.emplace_back(tmp);
//	}
//	sort(nums.begin(), nums.end());
//
//	tmp = nums[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (nums[i] - nums[i - 1] == 1) continue;
//		else
//		{
//			sum += tmp;
//			tmp = nums[i];
//		}
//	}
//	sum += tmp;
//
//	cout << sum;
//
//	return 0;
//}

/*B. Ö½ÅÆÄ§Êõ*/
/*Ä£Äâ*/
//#include<iostream>
//#include<string.h>
//
//using namespace std;
//
//int main()
//{
//	char str[51] = { 0 };
//	char ans[26] = { 0 };
//
//	cin >> str;
//	for (int i = 0; i < strlen(str); i++)
//		if (ans[str[i] - 'a'] == 1)
//		{
//			cout << "0";
//			return 0;
//		}
//		else ans[str[i] - 'a']++;
//
//	cout << "1";
//	return 0;
//}


/*D. Ð¡ÇòÅä¶Ô - 20% */
//#include<stdlib.h>
//#include<vector>
//#include<set>
//#include<iostream>
//using namespace std;
//
//int n, m;
//vector < pair<int, int> > vec;
//int ans[200007];
//int MIN = 2 * 1e6;
//
//
//void Min()
//{
//	int cnt = 0;
//	for (int i = 0; i < n; i++) if (ans[0] % 2 == 1) cnt++;
//	MIN = min(MIN, cnt);
//	return;
//}
//
//void Dfs(int step)
//{
//	if (step == n)
//	{
//		Min();
//		return;
//	}
//
//	ans[vec[step].first ]++;
//	Dfs(step + 1);
//	ans[vec[step].first]--;
//
//	ans[vec[step].second]++;
//	Dfs(step + 1);
//	ans[vec[step].second]--;
//
//}
//
//
//
//int main()
//{
//	int v1 = 0, v2 = 0;
//
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v1 >> v2;
//		vec.emplace_back(make_pair(v1, v2));
//	}
//	Dfs(0);
//
//	cout << MIN;
//
//	return 0;
//}