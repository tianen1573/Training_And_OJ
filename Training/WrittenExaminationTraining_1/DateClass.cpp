
// 根据输入的日期，计算是这一年的第几天。保证年份为4位数且日期合法。
// 进阶:时间复杂度:O(n)，空间复杂度:O(1)

#include<iostream>

using namespace std;

int days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

bool isLeapYear(int year)
{
    return ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
}

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    
    int res = 0;
    
    res += days[m - 1] + d;
    
    if(m > 2 && isLeapYear(y))
    {
        ++res;
    }
    
    cout << res;
    
    return 0;
}