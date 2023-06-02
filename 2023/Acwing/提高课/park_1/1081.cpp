// //这个数恰好等于 K 个互不相等的 B 的整数次幂之和。
// //代表转换后的数只允许出现01

// #include <iostream>
// #include <cstring>
// #include <vector>

// using namespace std;

// const int N = 35;//最多32位数

// int f[N][N];//长度为i， 其中有k个1 的 方案数

// int k, b;
// int x, y;

// void init()
// {
//     //dp
//     //...
//     //组合数：C(n, k) = C(n-1, k) + C(n-1, k - 1);
//     for(int i = 0; i < N; ++ i)
//     {
//         for(int j = 0; j <= i; ++j)
//         {
//             if(j == 0) f[i][j] = 1;//初始化
//             else f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
//         }
//     }
// }

// int dp(int x)
// {
//     // 处里边界问题
//     if(x == 0) return 0;
    
//     //进制转换
//     vector<int> nums;
//     while(x)
//     {
//         nums.push_back(x % b);
//         x /= b;
//     }
    
//     int res = 0;//记录答案
//     int last = 0;//保存迭代过程需要数据
    
//     //分部讨论
//     for(int i = nums.size() - 1; i >= 0; -- i)
//     {
//         int val = nums[i];
        
//         //是否讨论
//         //只有val>0时，才存在左右分支的概念， 否则只存在右分支
//         if(val > 0)
//         {
//             //讨论左分支，右分支，非法状态
//             //...
            
//             //左分支一定可以取0，取0，则剩下的i-1-0+1位，需要取k-last个1
//             res += f[i][k - last];
            
//             //如果val > 1, 左分支才有机会选择1，左分支可选择的是0~val-1
//             if(val > 1)
//             {
//                 //本题的有效数字是01，若左分支选择了1，则右分支就是非法的，不再存在
//                 if(k - last - 1 >= 0)
//                     res += f[i][k - last -1];
                
//                 //左分支选了1，右分支没有可选的数值
//                 break;
//             }
//             //此时，左分支只能选0，右分支选1
//             else
//             {
//                 ++ last;
//                 if(last > k) break;
//             }
        
//         }
        
//         //是否满足提前结束条件
//         //最右端点，且满足1的个数，则x也是一个满足要求的数
//         if(!i && last == k) ++ res;
//     }
    
//     return res;
// }

// int main()
// {
//     init();
    
//     cin >> x >> y >> k >> b;
    
//     cout << dp(y) - dp(x - 1) << endl;
    
//     return 0;
// }


#include <iostream>
#include <cstring>

using namespace std;

const int N = 35;
//记忆化的f[i][j]代表的是不贴上界，当前位置是i，之前的数是j的情况下的合法方案。
int f[N][N];//深度为i时，1的个数为 k-j 的 方案数
int arr[N], cnt;

int l, r, k, b;

//limit：上限为1
//st : 已经分配的1的个数
int dp(int pos, int st, int limit)
{
    //1.边界条件
    if(pos == 0) return st == k;
    //2.没有限制代表可以提前返回
    if(!limit && ~f[pos][st]) return f[pos][st];
    //3.模拟区间
    int res = 0, maxx = limit ? arr[pos] : b - 1;//有限制则最多为arr[pos]即上界，无限制则取当前进制最大数
    for(int i = 0; i <= maxx; ++ i)
    {
        //1的个数已经够了，大于1
        if((i == 1 && st == k) || i > 1) continue;
        res += dp(pos - 1, st + (i == 1), limit && (i == maxx));
    }
    
    return limit ? res : f[pos][st] = res;
}

int calc(int x)
{
    cnt = 0;
    memset(f, -1, sizeof f);
    
    while(x) arr[++ cnt] = x % b, x /= b;
    
    return dp(cnt, 0, 1);
}

int main()
{
    cin >> l >> r >> k >> b;
    
    cout << calc(r) - calc(l - 1)<< endl;
    
    return 0;
}