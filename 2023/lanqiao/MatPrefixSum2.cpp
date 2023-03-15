//±äĞÎ¾ØÕóºÍ
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;


const int N = 5007;
int sum[N][N];
int n, r, q;

int main()
{
    scanf("%d%d", &n, &r);
    int x, y, w;
    int mx = 0, my = 0, ww = 0;
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d%d%d", &x, &y, &w);
        sum[x + 1][y + 1] += w;
        mx = max(mx, x + 1);
        my = max(my, y + 1);
        //ww += w;
    }
    
    //cout << mx << " " << my << endl;
             
    long long mmax = 0;
    for (int i = 1; i <= mx; i++)
        for (int j = 1; j <= my; j++)
        {
            int I = max(i - r, 0);
            int J = max(j - r, 0);
            sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][ j -1];
            long long tmp = sum[i][j] - sum[i][J] - sum[I][j] + sum[I][J];
            mmax = max(mmax, (long long)tmp);
        }
            
    
    printf("%d", mmax);
    //printf("\n%d", ww);
    
    
    return 0;
}