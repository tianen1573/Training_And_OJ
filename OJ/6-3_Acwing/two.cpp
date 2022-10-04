#define _CRT_SECURE_NO_WARNINGS 1

/*二分模板*/
/* https://www.acwing.com/problem/content/791/ */
//#include<stdlib.h>
//#include<iostream>
//
//using namespace std;
//
//const int N = 1e5 + 7;
//int nums[N];
//
//int main()
//{
//    int n = 0, q = 0;
//    int val = 0;
//    cin >> n >> q;
//
//    for (int i = 1; i <= n; i++) cin >> nums[i];
//
//    while (q--)
//    {
//        cin >> val;
//
//        int l = 1, r = n;
//        while (l < r)
//        {
//            int mid = (l + r) >> 1;//[l, mid], [mid + 1, r],使用mid = l+r >> 1
//            if (nums[mid] >= val) r = mid;
//            else l = mid + 1;
//        }
//
//        if (nums[l] != val) cout << "-1 -1" << endl;
//        else
//        {
//            cout << l - 1 << " ";
//            r = n;
//            while (l < r)
//            {
//                int mid = (l + r + 1) >> 1;//[l, mid - 1], [mid, r],使用mid = l+r+1 >> 1
//                if (nums[mid] <= val) l = mid;
//                else r = mid - 1;
//            }
//
//            cout << r - 1 << " " << endl;
//        }
//    }
//
//    return 0;
//}

/*数的三次方根*/
/* https://www.acwing.com/problem/content/792/ */
//#include <stdlib.h>
//#include <iostream>
//
//using namespace std;
//
//double f = 0;
//double cf = 0;
//
//double bsearch_3(double l, double r)
//{
//    const double eps = 1e-8;
//    while (r - l > eps)
//    {
//        double mid = (l + r) / 2;
//        if (mid * mid * mid > f) r = mid;
//        else l = mid;
//    }
//
//    return l;
//}
//
//int main()
//{
//
//
//    cin >> f;
//    cf = bsearch_3(-100, 100);
//
//    printf("%.6f", cf);//cout格式化控制？？？
//    return 0;
//}

