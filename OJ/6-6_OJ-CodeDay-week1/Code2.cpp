#define _CRT_SECURE_NO_WARNINGS 1

/*性感素数*/
/* https://www.acwing.com/problem/content/4271/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//int N;
//
//bool Pri(int x)
//{
//
//    if (x <= 1)
//        return false;
//
//    for (int i = 2; i <= sqrt(x); i++)
//        if (x % i == 0) return false;
//
//    return true;
//}
//
//
//int main()
//{
//    cin >> N;
//
//    //先判断 N 是不是 性感素数
//    if ((Pri(N) && Pri(N - 6)) || (Pri(N) && Pri(N + 6)))
//    {
//        cout << "Yes" << endl;
//        if (Pri(N - 6)) cout << N - 6;//取小值
//        else cout << N + 6;
//        return 0;
//    }
//
//    cout << "No" << endl;
//    for (int i = N + 1; ; i++)
//        if (Pri(i) && Pri(i - 6))
//        {
//            if (i - 6 > N) cout << i - 6;//大于 N 的 最小 性感素数
//            else cout << i;
//            return 0;
//        }
//
//    return 0;
//}

/*校庆*/
/* https://www.acwing.com/problem/content/description/4272/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <set>
//#include <unordered_set>
//
//using namespace std;
//
//unordered_set<string> alu;
//string peoMax = "zzzzzzzzzzzzzzzzzz";
//string aluMax = "zzzzzzzzzzzzzzzzzz";
//
//int cnt;
//
//int N, M;
//
//int main()
//{
//    cin >> N;
//    for (int i = 0; i < N; i++)
//    {
//        string tmp;
//        cin >> tmp;
//        alu.insert(tmp);
//    }
//    cin >> M;
//    for (int i = 0; i < M; i++)
//    {
//        string tmp;
//        cin >> tmp;
//
//        if (alu.count(tmp) == 1)
//        {
//            cnt++;//更新校友人数
//            if (aluMax.substr(6, 8) > tmp.substr(6, 8)) aluMax = tmp;//更新校友长者
//        }
//        if (peoMax.substr(6, 8) > tmp.substr(6, 8)) peoMax = tmp;//更新来宾长者
//    }
//
//    cout << cnt << endl;
//
//    if (cnt) cout << aluMax;
//    else cout << peoMax;
//
//    return 0;
//}

