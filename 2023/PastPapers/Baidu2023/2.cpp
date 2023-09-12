// 讨厌鬼有n个帖子。第i个帖子的点赞数为ai ,点踩数为bi。你可以选择任意个帖子组合起来，
// 组合帖子的点赞数和点踩数为所有被组合帖子点赞数和点踩数之和。
// 已知一个帖子的点赞数为α，点踩数为J，则该帖子的吸引度为|x -g|。
// 讨厌鬼需要选择若干个帖子组合起来，使得这个组合帖子的吸引度尽可能大。请你告诉他这个吸引度最大是多少?
// 第一行输入一个整数n;(1 ≤ n ≤ 10^5)。
// 第二行输入n个整数ai;(1 ≤ a ≤ 10^9)。
// 第三行输入n个整数bi;(1 ≤ bi ≤ 10^9)。


#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> yes(n), no(n);
    for(int i = 0; i < n; ++ i)
        cin >> yes[i];
    for(int i = 0; i < n; ++ i)
        cin >> no[i];

    unsigned long long yesSum = 0, noSum = 0;
    for(int i = 0; i < n; ++ i)
    {
        if(yes[i] > no[i])
        {
            yesSum += (yes[i] - no[i]);
        }
        else
        {
            noSum += (no[i] - yes[i]);
        }
    }

    unsigned long long ans = max(yesSum, noSum);
    cout << ans;

    return 0;
}