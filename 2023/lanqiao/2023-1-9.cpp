#include <iostream>
#include <algorithm>

using namespace std;

const long long N = (long long)202320232023;
uint64_t SUM = 0;
uint64_t CAL = 1;

int main()
{
    for(int i = 1; i <= 40; ++ i)
    {
        CAL = (CAL * i) % 1000000000;
        SUM = (SUM + CAL) % 1000000000;
    }

    cout << SUM << endl;//420940313
    cout << UINT32_MAX << endl;

    return 0;
}