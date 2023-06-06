#include <iostream>
#include <algorithm>

using namespace std;

int getSum(int x, int b)
{
    int sum = 0;
    while(x) sum += (x % b), x /= b;

    return sum;
}

int main()
{
    int cnt = 0;

    long long cur = 1;

    while(cnt < 2023)
    {
        if(cur % getSum(cur, 10) || cur % getSum(cur, 2) || cur % getSum(cur, 8) || cur % getSum(cur, 16))
        {
            cur ++;
        }
        else
        {
            cnt ++;
            cur ++;
        }
    }


    cout << cur - 1;
    return 0;
}