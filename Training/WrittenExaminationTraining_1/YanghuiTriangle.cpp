// 以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数、左上角数和右上角的数，3个数之和（如果不存在某个数，认为该数就是0)。
// 求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3，输入2则输出-1。
// 数据范围: 1≤n ≤109
#include<iostream>
#include<vector>

using namespace std;

// 10^9 行， 无法生成类杨辉三角 或者 两个数组dp
// 将数阵写出来， 发现从第3行开始， 4行一循环， 第一个偶数 出现在 2， 3， 2， 4 位置

int main()
{
    int n = 0;
    cin >> n;
    int res[] = {2, 3, 2, 4};
    
    if(n <= 2)
    {
        cout << "-1";
    }
    else
    {
        cout << res[(n - 3) % 4];
    }
    
    return 0;
}