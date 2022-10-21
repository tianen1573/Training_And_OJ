// 求一个int类型数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
// 数据范围:数据组数: 1<t≤5，1 <n ≤500000进阶:时间复杂度:O(logn)，空间复杂度:O(1)
#include<iostream>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    
    int res = 0, cnt = 0;
    
    for(int i = 0; i < 32; ++i)
    {
        if(num >> i & 1)
        {
            ++cnt;
        }
        else
        {
            res = max(res, cnt);
            cnt = 0;
        }
    }
    
    cout << res;
    
    return 0;
}