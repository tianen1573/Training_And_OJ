#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
long long ans = 0;
unordered_map<int, vector<int>> mm;
vector<int> arr;
void dfs(int pre, int u)
{
    ans += (arr[pre] & arr[u]);
    ans %= MOD;

    for(auto son : mm[u])
    {
        if(pre == son)
            continue;
        else
         dfs(u, son);
    }
}

int main() 
{
    int n;
    cin >> n;
    arr = vector<int>(n + 1);
    for(int i = 1; i <= n; ++ i)
        scanf("%d", &arr[i]);
    
    for(int i = 1; i < n; ++ i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        mm[u].push_back(v);
        mm[v].push_back(u);
    }

    for(auto son : mm[1])
    {
        dfs(1, son);
    }
    
    cout << ans;

    return 0;
}
// 64 位输出请用 printf("%lld")