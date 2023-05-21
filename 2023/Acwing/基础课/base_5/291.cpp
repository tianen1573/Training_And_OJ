// // 作者：松鼠爱葡萄
// // 链接：https://www.acwing.com/solution/content/15616/
// #include<iostream>
// #include<cstring>

// using namespace std;

// //数据范围1~11
// const int N = 12;
// //每一列的每一个空格有两种选择，放和不放，所以是2^n
// const int M = 1 << N;
// //方案数比较大，所以要使用long long 类型
// //f[i][j]表示 i-1列的方案数已经确定，从i-1列伸出，并且第i列的状态是j的所有方案数
// long long f[N][M];
// //第 i-2 列伸到 i-1 列的状态为 k ， 是否能成功转移到 第 i-1 列伸到 i 列的状态为 j
// //st[j|k]=true 表示能成功转移
// bool st[M];
// //n行m列
// int n, m;

// int main() {
// //    预处理st数组
//     while (cin >> n >> m, n || m) {
        
//         //将空白为计数的状态给处理掉
//         for (int i = 0; i < 1 << n; i++) {
// //            第 i-2 列伸到 i-1 列的状态为 k ， 
// //            能成功转移到 
// //            第 i-1 列伸到 i 列的状态为 j
//             st[i] = true;
// //            记录一列中0的个数
//             int cnt = 0;
//             for (int j = 0; j < n; j++) {
// //                通过位操作，i状态下j行是否放置方格，
// //                0就是不放， 1就是放
//                 if (i >> j & 1) {
// //                    如果放置小方块使得连续的空白格子数成为奇数，
// //                    这样的状态就是不行的，
//                     if (cnt & 1) {
//                         st[i] = false;
//                         break;
//                     }
//                 }else cnt++;
// //                不放置小方格
//             }

//             if (cnt & 1) st[i] = false;
//         }

// //        初始化状态数组f
//         memset(f, 0, sizeof f);

// //        棋盘是从第0列开始，没有-1列，所以第0列第0行，不会有延伸出来的小方块
// //        没有横着摆放的小方块，所有小方块都是竖着摆放的，这种状态记录为一种方案
//         f[0][0] = 1;
// //        遍历每一列
//         for (int i = 1; i <= m; i++) {
// //            枚举i列每一种状态
//             for (int j = 0; j < 1 << n; j++) {
// //                枚举i-1列每一种状态
//                 for (int k = 0; k < 1 << n; k++) {
// //                    f[i-1][k] 成功转到 f[i][j]
//                     if ((j & k) == 0 && st[j | k]) {
//                         f[i][j] += f[i - 1][k]; //那么这种状态下它的方案数等于之前每种k状态数目的和
//                     }
//                 }
//             }
//         }
// //        棋盘一共有0~m-1列
// //        f[i][j]表示 前i-1列的方案数已经确定，从i-1列伸出，并且第i列的状态是j的所有方案数
// //        f[m][0]表示 前m-1列的方案数已经确定，从m-1列伸出，并且第m列的状态是0的所有方案数
// //        也就是m列不放小方格，前m-1列已经完全摆放好并且不伸出来的状态
//         cout << f[m][0] << endl;
//     }
//     return 0;
// }


// 作者：yxc
// 链接：https://www.acwing.com/activity/content/code/content/64200/
// 去除无效状态的优化写法 -- 把ij合法的统计起来
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << N;

int n, m;
LL f[N][M];
vector<int> state[M];
bool st[M];

int main()
{
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < 1 << n; i ++ )
        {
            int cnt = 0;
            bool is_valid = true;
            for (int j = 0; j < n; j ++ )
                if (i >> j & 1)
                {
                    if (cnt & 1)
                    {
                        is_valid = false;
                        break;
                    }
                    cnt = 0;
                }
                else cnt ++ ;
            if (cnt & 1) is_valid = false;
            st[i] = is_valid;
        }

        for (int i = 0; i < 1 << n; i ++ )
        {
            state[i].clear();
            for (int j = 0; j < 1 << n; j ++ )
                if ((i & j) == 0 && st[i | j])
                    state[i].push_back(j);
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; i ++ )
            for (int j = 0; j < 1 << n; j ++ )
                for (auto k : state[j])
                    f[i][j] += f[i - 1][k];

        cout << f[m][0] << endl;
    }

    return 0;
}


