// 小红和朋友玩游戏，棋盘为n × m的坐标轴。
// 有一颗棋子在坐标(1,1)的位置，每次可以向上或者向右移动奇数单位，
// 不能移动到棋盘外面，无法行动就输了，小红先手，请问小红能否必胜。
//一行一个整数t，表示有t 组数据。
// 接下来t行，每行两个整数n和m，表示棋盘大小。1 ≤t ≤ 10^4
// 1 ≤ n, m ≤ 10^3


#include <iostream>
using namespace std;

int main() 
{
    int t;
    cin >> t;

    while(t --)
    {
        int n, m;
        cin >> n >> m;
        int sum = n + m;
        if(sum & 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}