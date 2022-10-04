#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//using namespace std;
//int Max = -1;
//int cnt;
//
//void MAX(long long x)
//{
//	cnt++;
//
//	if (x == 2)
//		Max = max(cnt, Max);
//	else if (x % 2 == 1)
//		MAX(x * 3 + 1);
//	else
//		MAX(x / 2);
//}
//
//
//int main()
//{
//	for (int i = 1; i <= 12345; i++)
//	{
//		cnt = 0;
//		MAX(i);
//	}
//
//	cout << Max;
//
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int ans[11605];
//int cnt = 2;
//int val = 123456;
//void Prime(int x)
//{
//	for (int i = 2; i <= sqrt(x); i++)
//		if (x % i == 0)
//			return;
//	
//	ans[cnt] = x;
//	cnt++;
//	return;
//}
//
//int main()
//{
//	ans[0] = 1, ans[1] = 2;
//	for (int i = 3; i <= val; i++)
//		Prime(i);
//
//	int rep = 0, p1 = 0, p2 = 0;
//
//	for(int i = 0; i < cnt; i++)
//		for (int j = 0; j < cnt && ans[i] + ans[j] <= val; j++) {
//			if (ans[i] + ans[j] == val)
//			{
//				p1++;
//			}
//		}
//
//	for(int i = 0; i < cnt; i++)
//		for(int j = 0; j < cnt; j++)
//			for (int k = 0; k < cnt && (long long)ans[j] * ans[k] <= val; k++) {
//				if (ans[i] + ans[j] * ans[k] == val)
//				{
//					if (k == j)
//						rep++;
//					p2++;
//				}			
//			}
//	
//	p2 += rep;
//
//	cout << p1 << " " << p2;
//	return 0;
//}

//#include<iostream>
//#include<stdlib.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<int> vec;
//int n;
//unsigned long long ans = 0;
//
//int main()
//{
//	cin >> n;
//	int tmp = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> tmp;
//		vec.emplace_back(tmp);
//	}
//	sort(vec.begin(), vec.end());
//
//	for (int i = n - 1, k = 0; i >= 0; i--, k++)
//		ans += vec[i] * (unsigned long long)(k + 1) * (k + 1);
//
//	printf("%lld", ans);
//
//	return 0;
//}

//#include<iostream>
//#include<stdlib.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<unsigned long long> vec;
//int n;
//unsigned long long ans = 0;
//
//int main()
//{
//	cin >> n;
//	unsigned long long tmp = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> tmp;
//		vec.emplace_back(tmp);
//	}
//	
//	for (int pos = 0, k = 1, tail = n - 1; pos <= n; k++)
//	{
//		if (vec[pos] < vec[n])
//		{
//			ans += vec[pos] * k * k;
//			pos++;
//		}
//		else
//		{
//			ans += vec[n] * k * k;
//			n--;
//		}
//		
//	}
//
//	printf("%lld", ans);
//
//	return 0;
//}