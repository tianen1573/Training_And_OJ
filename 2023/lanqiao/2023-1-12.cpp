#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long x1, y1, x2, y2, x3, y3, x4, y4, xa, ya, xb, yb;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    xa = max(x1, x3);
    ya = max(y1, y3);
    xb = min(x2, x4);
    yb = min(y2, y4);

    long long sum = 0;
    if(xa < xb && ya < yb) sum = (xb - xa) * (yb - ya);

    cout << (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3) - sum;

    return 0;
}