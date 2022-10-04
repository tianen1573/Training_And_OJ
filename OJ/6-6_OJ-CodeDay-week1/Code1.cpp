#define _CRT_SECURE_NO_WARNINGS 1

/*你知道你的ABC吗*/
/* https://www.acwing.com/problem/content/3349/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int nums[7];
//
//int main()
//{
//    for (int i = 0; i < 7; i++) cin >> nums[i];
//
//    sort(nums, nums + 7);
//
//    cout << nums[0] << " " << nums[1] << " " << nums[6] - nums[0] - nums[1];
//
//    return 0;
//}

/*放羊但没完全放养*/
/*https://www.acwing.com/problem/content/description/3361/*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <string.h>
//
//using namespace std;
//
//int cnt;
//
//int main()
//{
//    string bss;
//    string fss;
//
//    cin >> bss >> fss;
//
//    int i = 0;//记录待听字符的位置
//
//    while (i < fss.size())
//    {
//        cnt++;//循环次数
//        for (int j = 0; j < bss.size(); j++)
//            if (bss[j] == fss[i])
//                i++;
//    }
//
//    cout << cnt;
//    return 0;
//}

/*牛年*/
/* https://www.acwing.com/problem/content/3373/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <stdlib.h>
////#include<pair>
//using namespace std;
//
//typedef pair<string, pair<string, int> > PSSI;//名字，生肖，周期
//typedef pair<string, int > PSI;//和牛年的年份差
//
//PSSI ans[107];
//PSI dif[12];
//
//int N;
//
//int main()
//{
//    //初始化Bessie的信息
//    ans[0].first = "Bessie";
//    ans[0].second.first = "Ox";
//    ans[0].second.second = 0;
//    //初始化各年份和牛年的差值
//    dif[0].first = "Ox", dif[0].second = 0;
//    dif[1].first = "Tiger", dif[1].second = 1;
//    dif[2].first = "Rabbit", dif[2].second = 2;
//    dif[3].first = "Dragon", dif[3].second = 3;
//    dif[4].first = "Snake", dif[4].second = 4;
//    dif[5].first = "Horse", dif[5].second = 5;
//    dif[6].first = "Goat", dif[6].second = 6;
//    dif[7].first = "Monkey", dif[7].second = 7;
//    dif[8].first = "Rooster", dif[8].second = 8;
//    dif[9].first = "Dog", dif[9].second = 9;
//    dif[10].first = "Pig", dif[10].second = 10;
//    dif[11].first = "Rat", dif[11].second = 11;
//
//
//
//    cin >> N;
//    getchar();//消除回车
//    for (int i = 0; i < N; i++)
//    {
//        int j = 0, lag = 0;
//        string pn, CmName;
//
//        cin >> ans[i + 1].first >> pn >> pn >> pn;
//        cin >> ans[i + 1].second.first >> CmName >> CmName >> CmName;
//
//        /*以下三个循环，可通过map/set直接定位，问题是我不会*/
//        int k = 0;
//        for (k; k < i + 1; k++)
//        {
//            if (ans[k].first.compare(CmName) == 0)//参照动物
//                break;
//        }
//        int cur = 0, next = 0;
//        for (int q = 0; q < 12; q++)
//        {
//            if (dif[q].first.compare(ans[i + 1].second.first) == 0)
//                cur = dif[q].second;
//        }
//        for (int q = 0; q < 12; q++)
//        {
//            if (dif[q].first.compare(ans[k].second.first) == 0)
//                next = dif[q].second;
//        }
//        //需要判断是否不同年
//        //上个轮回，记 -1，下个轮回 记 +1
//        if (pn[0] == 'p' && cur >= next)
//            lag = -1;
//        else if (pn[0] == 'n' && cur <= next)
//            lag = 1;
//
//
//        ans[i + 1].second.second = ans[k].second.second + lag;
//
//        if (ans[i + 1].first == "Elsie")//结束
//            break;
//    }
//
//    int year = 0, Dif = 0;
//    string E_zodi;
//
//    int k = 0;
//    for (k; k <= N; k++)
//    {
//        if (ans[k].first.compare("Elsie") == 0)
//            break;
//    }
//
//    E_zodi = ans[k].second.first;
//
//    for (int i = 0; i < 12; i++)
//    {
//        if (dif[i].first.compare(E_zodi) == 0)
//            Dif = dif[i].second;
//    }
//
//    year = ans[k].second.second * 12 + Dif;
//    cout << abs(year);
//
//    return 0;
//}


/*牛的学术圈*/
/* https://www.acwing.com/problem/content/3748/ */
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N, L, h;
//int nums[100007];
//
//
//int main()
//{
//    cin >> N >> L;
//    for (int i = 1; i <= N; i++) cin >> nums[i];
//
//    sort(nums + 1, nums + 1 + N, greater<int>());
//
//    //枚举不引用时，最大指数
//    for (int i = 1; i <= N; i++)
//        if (nums[i] >= i) h = i;
//        else break;
//
//    /*
//    i = h 时， 只有 nums[h+1] = h, 则在 i = h+1 时，nums[h+1] + 1 == h + 1 == i，交点才会上移
//    */
//    if (nums[h + 1] < h)//只有第三种状态才能增加指数
//    {
//        cout << h;
//        return 0;
//    }
//
//    int cnt = 0, ptrh = h + 1;
//    while (ptrh >= 1 && nums[ptrh] == h) ptrh--;
//    cnt = h + 1 - ptrh;
//
//    if (L >= cnt) h++;
//
//    cout << h;
//    return 0;
//}

/*奶牛体操*/
/* https://www.acwing.com/problem/content/1461/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//bool ans[23][23];
//int que[23];
//
//int N, K;
//
//int main()
//{
//    cin >> K >> N;
//
//    for (int i = 1; i <= K; i++)
//        for (int j = 1; j <= N; j++)
//        {
//            cin >> que[j];
//            for (int m = 1; m < j; m++) ans[que[m]][que[j]] = true;//表示存在过（a,b）顺序对
//        }
//
//    int ret = N * (N - 1) / 2;//最多个数
//    for (int i = 1; i <= N; i++)
//        for (int j = i + 1; j <= N; j++)
//            if (ans[i][j] == ans[j][i]) ret--;//根据题意：（a,b）和（b,a）不能同时存在
//
//    cout << ret;
//
//    return 0;
//}


