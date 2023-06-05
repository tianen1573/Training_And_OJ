#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int n;

int main()
{
    cin >> n;

    int downv = -0x3f3f3f3f, upv = 0x3f3f3f3f;

    for(int i = 1; i <= n; ++ i)
    {
        int a, b; cin >> a >> b;

        downv = max(downv, a / (b + 1) + 1);
        upv = min(upv, a / b);
    }

    cout << downv << ' ' << upv;

    return 0;
}