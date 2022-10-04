#define _CRT_SECURE_NO_WARNINGS 1

/*方形牧场*/
/* https://www.acwing.com/problem/content/1814/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int ax1, ax2, ay1, ay2;
//int bx1, bx2, by1, by2;
//
//int x1, x2, y1, y2;
//
//int main()
//{
//    cin >> ax1 >> ay1 >> ax2 >> ay2;
//    cin >> bx1 >> by1 >> bx2 >> by2;
//
//    x1 = min(ax1, bx1); y1 = min(ay1, by1);
//    x2 = max(ax2, bx2); y2 = max(ay2, by2);
//
//    int side = max(x2 - x1, y2 - y1);
//
//    cout << side * side;
//
//    return 0;
//}

/*不做最后一个！*/
/* https://www.acwing.com/problem/content/1802/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
//#define x first
//#define y second
//
//typedef unordered_map<string, int> UMSI;
//UMSI m;
//vector<int> vec;
//
//int main()
//{
//    //初始化
//    m["Bessie"] = 0;
//    m["Elsie"] = 0;
//    m["Daisy"] = 0;
//    m["Gertie"] = 0;
//    m["Annabelle"] = 0;
//    m["Maggie"] = 0;
//    m["Henrietta"] = 0;
//
//    //读入
//    int n; cin >> n;
//    string a; int b;
//    while (n--) {
//        cin >> a >> b;
//        m[a] += b;
//    }
//    //把奶量转移到数组中，并排序
//    for (auto mv : m)
//        vec.push_back(mv.y);
//    sort(vec.begin(), vec.end());
//
//    int nmin = vec[0], cnt = 0, i = 1;//次最小值，次最小值个数
//    //找此最小值
//    for (; i < 7; i++)
//        if (vec[i] > vec[0])
//        {
//            nmin = vec[i];
//            break;
//        }
//    //记录个数
//    for (; i < 7; i++)
//        if (vec[i] == nmin)
//            cnt++;
//
//    //输出
//    if (nmin == vec[0] || cnt > 1)
//        cout << "Tie";
//    else
//    {
//        for (auto mv : m)
//            if (mv.y == nmin)
//            {
//                cout << mv.x;
//                break;
//            }
//    }
//
//    return 0;
//}

/*牛为什么过马路*/
/* https://www.acwing.com/problem/content/1790/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//bool one[11];//记录第一次位置
//bool side[11];//记录第n次观察前的位置
//int ans;
//
//int n;
//
//int main()
//{
//    cin >> n;
//    int num; bool s;
//    while (n--)
//    {
//        cin >> num >> s;
//        if (!one[num]) one[num] = true, side[num] = s;
//        else if (side[num] != s) ans++, side[num] = s;
//    }
//
//    cout << ans;
//    return 0;
//}

/*丢失的牛*/
/* https://www.acwing.com/problem/content/description/1777/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//
//int x, y;
//
//int main()
//{
//    cin >> x >> y;
//    int len = abs(x - y);
//
//    int i = 0;
//    for (i = 0; ; i++)
//    {
//        /*人牛相对位置不同，i结束值不同*/
//        if ((y >= x) && (int)pow(2, i) >= len) break;
//        i++;
//        if ((x > y) && (int)pow(2, i) >= len) break;
//    }
//
//    int dis = 2 * (pow(2, i) - 1) + len;
//    cout << dis;
//
//    return 0;
//}

/*围栏刷漆*/
/* https://www.acwing.com/problem/content/description/1868/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int a, b, c, d;
//
//int main()
//{
//    cin >> a >> b >> c >> d;
//
//    int len = 0;
//
//    if (c > b || d < a) len = (b - a) + (d - c);//不重合
//    else len = (max(a, max(b, max(c, d))) - min(a, min(b, min(c, d))));//重合
//
//    cout << len;
//
//    return 0;
//}

/*晋升计数*/
/* https://www.acwing.com/problem/content/1856/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int p[4][2];
//
//int a, b, c;
//
//int main()
//{
//    for (int i = 0; i < 4; i++)
//        cin >> p[i][0] >> p[i][1];
//
//    c = p[3][1] - p[3][0];//白金 后 - 前
//    b = p[2][1] - (p[2][0] - c);//金后 - (金前 - 晋级) 
//    a = p[1][1] - (p[1][0] - b);//银后 - (银前 - 晋级)
//
//    cout << a << endl << b << endl << c;
//
//    return 0;
//}