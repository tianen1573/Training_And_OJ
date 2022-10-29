// 有一种兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子。
// 例子:假设一只兔子第3个月出生，那么它第5个月开始会每个月生一只兔子。
// 一月的时候有一只兔子，假如兔子都不死，问第n个月的兔子总数为多少?
#include<iostream>
using namespace std;

int main()
{
    int prePre = 1, pre = 1, cur = 0;
    int n = 0;
    cin >> n;
    for(int i = 2; i < n; ++ i)
    {
        cur = pre + prePre;
        prePre = pre;
        pre = cur;
    }
    
    cout << cur;
    
    return 0;
}
