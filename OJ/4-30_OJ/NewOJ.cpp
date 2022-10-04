#define _CRT_SECURE_NO_WARNINGS 1

/*week_7*/
/* http://oj.ecustacm.cn/contest.php?cid=1021 */
/*A*/
//#include <stdio.h>
//
//char a[5], b[5];
//int count = 1;
//
//int main()
//{
//	scanf("%s", a);
//	scanf("%s", b);
//
//	char *ta = a, *tb = b;
//
//	while (*ta)
//	{
//		if (*ta != *tb)
//			count *= 2;
//		ta++;
//		tb++;
//	}
//
//	printf("%d", count);
//
//	return 0;
//}

/*B*/
//#include<map>
//#include<stdlib.h>
//#include<iostream>
//using namespace std;
//const int maxn = 1e5 + 10;
//int a[maxn];
//int main()
//{
//    int T;
//    cin >> T;
//    while (T--)
//    {
//        int n, F;
//        cin >> n >> F;
//        map<int, int>Map;
//        //统计每个数字出现次数
//        for (int i = 1; i <= n; i++)
//        {
//            cin >> a[i];
//            Map[a[i]]++;
//        }
//        long long ans1 = 0, ans2 = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            int H = a[i];
//            ans1 += Map[H] - 1;
//            while (H && H % F == 0)
//            {
//                H /= F;
//                ans2 += Map[H];
//            }
//        }
//        cout << ans1 / 2 + ans2 << endl;
//    }
//    return 0;
//}

/*C*/
//#include<stdio.h>
//
//int T;
//
//int main()
//{
//	scanf("%d", &T);
//	while (T)
//	{
//		int a_count = 0, b_count = 0;
//		int lag = 0;
//		char *slow = NULL, *fast = NULL;
//		char s[100001];
//		int len[2] = { 0 };
//
//		scanf("%s", s);
//		slow = s;
//		fast = s;
//		while (*fast)
//		{
//			if (*fast == *slow && (*fast == 'A' || *fast == 'B'))
//			{
//				char tmp = *slow;
//				while (slow < fast)
//				{
//					len[tmp - 'A']++;
//					slow++;
//				}
//			}
//			else if(*fast != '.' && *fast != *slow)
//			{
//				char tmp = *slow;
//				len[tmp - 'A']++;
//				slow = fast;
//			}
//			fast++;
//		}
//		len[*slow - 'A']++;
//
//		printf("%d %d\n", len[0], len[1]);
//
//		T--;
//	}
//
//	return 0;
//}

/*D*/
/* 36% */
//#include<stdio.h>
//#include<math.h>
//
//int n, m, x, l, r;
//int arr[100001];
//unsigned long long sum[100001];
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	scanf("%d", &m);
//	while (m)
//	{
//		scanf("%d %d %d", &x, &l, &r);
//
//		if (1 == x)
//		{
//			unsigned long long sum = 0;
//			for (int i = l; i <= r; i++)
//			{
//				sum += arr[i];
//			}
//			printf("%lld\n", sum);
//		}
//		else if (2 == x)
//		{
//			for (int i = l; i <= r; i++)
//			{
//				arr[i] = sqrt(arr[i]);
//			}
//		}
//
//		m--;
//	}
//
//	return 0;
//}

#include<stdlib.h>
#include<iostream>
#include<map>
#include<set>
#include<stdio.h>
using namespace std;

int main()
{

	set<int, int> SET;


	return 0;
}