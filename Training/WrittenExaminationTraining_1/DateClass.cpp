
// ������������ڣ���������һ��ĵڼ��졣��֤���Ϊ4λ�������ںϷ���
// ����:ʱ�临�Ӷ�:O(n)���ռ临�Ӷ�:O(1)

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