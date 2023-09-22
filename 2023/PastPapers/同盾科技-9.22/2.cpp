#include <iostream>
#include <vector>
using namespace std;

const int V = 1e5;

bool f[2][V] = {false};

int main() 
{
    int v, n;
    cin >> v >> n;
    vector<int> arr(n + 1, 0);
    for(int i = 1; i <= n; ++ i)
        cin >> arr[i];
    
    f[0][0] = f[1][0] = true;
    for(int i = 1; i <= n; ++ i)
        for(int j = 0; j <= v; ++ j)
        {
            f[i & 1][j] = f[(i - 1) & 1][j];
            if(j >= arr[i])
                f[i & 1][j] |= f[(i - 1) & 1][j - arr[i]];
        }
            
    
    for(int i = v; i >= 0; -- i)
        if(f[0][i] || f[1][i])
        {
            cout << v - i;
            return 0;
        }
    
    cout << v;
    return 0;
    
}
// 64 位输出请用 printf("%lld")
