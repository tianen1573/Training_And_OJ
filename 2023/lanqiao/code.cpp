#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t; cin >> t;

    while(t --)
    {
        int n; cin >> n;
        int odd = 0, even = 0;

        int tmp;
        for(int i = 0; i < n; ++ i)
        {
            cin >> tmp;
            if(tmp % 2) ++ odd;
            else ++ even;
        }

        if(odd % 2 == 1) cout << 0 << endl;
        else
        {
            if(odd == 0) odd = 1;
            cout << ( ((long long)pow(2, even) % 1000000007) * ((long long)pow(2, odd - 1) % 1000000007) ) % 1000000007 << endl;
        }
        
    }

    return 0;
}