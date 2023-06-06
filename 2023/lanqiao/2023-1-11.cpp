#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1011;

int f[N][2];
int h[N];

int t;
int main()
{
    cin >> t;

    while(t -- )
    {
        int n; cin >> n;
        long long sum = 0;
        for(int i = 1; i <= n; ++ i)
        {
            cin >> h[i];
            sum += h[i];
        }

        if(sum % 2)
        {
            cout << 0 << endl;
            continue;
        }

        int odd = 0, even = 0;
        for(int i = 1; i <= n; ++ i)
        {
            if(h[i] % 2)//奇数
            {
                f[i][1] = even + 1;
                f[i][0] = odd;

                even = (even + f[i][0]) % 1000000007;
                odd = (odd + f[i][1]) % 1000000007; 
            }
            else//偶数
            {
                f[i][0] = even + 1;
                f[i][1] = odd;

                even = (even + f[i][0]) % 1000000007;
                odd = (odd + f[i][1]) % 1000000007;  
            }
        }
        ++ even;

        cout << even % 1000000007 << endl;
    }

    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <cmath>

// using namespace std;

// int main()
// {
//     int t; cin >> t;

//     while(t --)
//     {
//         int n; cin >> n;
//         int odd = 0, even = 0;

//         int tmp;
//         for(int i = 0; i < n; ++ i)
//         {
//             cin >> tmp;
//             if(tmp % 2) ++ odd;
//             else ++ even;
//         }

//         if(odd % 2 == 1) cout << 0 << endl;
//         else
//         {
//             if(odd == 0) odd = 1;
//             cout << ( ((long long)pow(2, even) % 1000000007) * ((long long)pow(2, odd - 1) % 1000000007) ) % 1000000007 << endl;
//         }
        
//     }

//     return 0;
// }