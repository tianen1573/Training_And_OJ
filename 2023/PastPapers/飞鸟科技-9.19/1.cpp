#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
    vector<vector<int>> arr(10001, vector<int>(2, 0));

    int n; cin >> n;
    for(int i = 0; i < n; ++ i)
    {
        int tmp; cin >> tmp;
        arr[tmp][1] += tmp;
    }

    int ans = 0;
    for(int i = 1; i < 10001; ++ i)
    {
        arr[i][0] = max(arr[i - 1][0], arr[i - 1][1]);
        arr[i][1] += arr[i - 1][0];
        ans = max(ans, max(arr[i][0], arr[i][1]));
    }
    

    cout << ans;
}
// 64 位输出请用 printf("%lld")