#include <iostream>
#include <cstring>

using namespace std;

const int N = 100011;

double f[N][2];
int h[N], a[N], b[N];

int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++ i)
        cin >> h[i];
    for(int i = 1; i < n; ++ i)
        cin >> a[i] >> b[i];
    
    f[1][0] = h[1];
    f[1][1] = h[1] + a[1] / 0.7;

    for(int i = 2; i <= n; ++ i)
    {
        f[i][0] = min(f[i - 1][0] + h[i] - h[i - 1], f[i - 1][1] + b[i - 1] / 1.3);
        f[i][1] = min(f[i][0] + a[i] / 0.7, f[i - 1][1] + (a[i] < b[i - 1] ?  (b[i - 1] - a[i]) / 1.3 : (a[i] - b[i - 1]) / 0.7));
    }

    double res = min(f[n][0], f[n][1] + a[n] / 1.3);

    printf("%.2lf", res);

    return 0;
}