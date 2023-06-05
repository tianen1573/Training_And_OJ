#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e5 + 11;

int f[N];
long long res, k;
char str[N];
char c1, c2;

int main()
{
    cin >> k >> str + 1 >> c1 >> c2;
    int len = strlen(str + 1);

    // cout << k << endl << (str + 1) << endl << c1 << endl << c2;
    for(int i = 1; i <= len; ++ i)
    {
        f[i] = f[i - 1];
        if(str[i] == c1) ++ f[i];

        if(i >= k && str[i] == c2)
        {
            res += f[i - k + 1];
            // cout << f[i - k + 1] << endl;
        }
    }

    cout << res;

    return 0;
}