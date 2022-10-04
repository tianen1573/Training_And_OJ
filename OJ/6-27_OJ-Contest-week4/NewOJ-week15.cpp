#define _CRT_SECURE_NO_WARNINGS 1

/* http://oj.ecustacm.cn/problem.php?cid=1036&pid=0 */

/*分糖果*/
//#include <stdlib.h>
//#include <iostream>
//using namespace std;
//
//int n, L, R, Max;
//
//int main()
//{
//	cin >> n >> L >> R;
//
//	int Lr = L % n;
//	int r = R - L + Lr;
//
//	if (r >= n) Max = n - 1;
//	else Max = r;
//
//	cout << Max;
//
//	return 0;
//}

/*小熊的果篮*/
//TML -- 70%
//#include <stdlib.h>
//#include <iostream>
//using namespace std;
//
//const int N = 2e5 + 7;
//
//int num[N];
//int n;
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &num[i]);
//	
//	int last = 2, lag = 0, head = 1;
//	for (int step = 0; ; )
//	{
//		last = 2;
//		lag = 0;
//		for (int i = head; i <= n; i++)
//		{
//			
//			if (num[i] == 2 || num[i] == last) continue;
//			else
//			{
//				if (!lag) head = i + 1;
//				lag = 1;
//				printf("%d ", i);
//				last = num[i];
//				num[i] = 2;
//			}
//		}
//		if (!lag) break;
//		printf("\n");
//	}
//
//
//	return 0;
//}
//
//err -- 30%
//#include <stdlib.h>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 2e5 + 7;
//
//vector<int> a, b;
//int num[N];
//int n;
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &num[i]);
//
//	int last = 2; a.push_back(2);
//	for (int i = 1; i <= n; i++)
//	{
//
//		if (num[i] == 2 || num[i] == last) continue;
//		else
//		{
//			a.push_back(i);
//			last = num[i];
//			num[i] = 2;
//		}
//	}
//	while (a.size() > 1)
//	{
//		last = 3;
//		b.push_back(2);
//		for (int i = 1; i < a.size(); i++)
//		{
//			printf("%d ", a[i]);
//			if (a[i] + 1 <= n && num[a[i] + 1] != last && num[a[i] + 1] != 2)
//			{
//				b.push_back(a[i] + 1);
//				last = num[a[i] + 1];
//				num[a[i] + 1] = 2;
//			}
//			else if(a[i] + 1 <= n && last == 3)
//			{
//				for(int l = a[i] + 1; l <= n; l++)
//					if (num[l] != 2)
//					{
//						last = num[l];
//						b.push_back(l);
//						num[l] = 2;
//						break;
//					}
//			}
//		}
//		printf("\n");
//		a = b;
//		b.clear();
//	}
//
//
//	return 0;
//}