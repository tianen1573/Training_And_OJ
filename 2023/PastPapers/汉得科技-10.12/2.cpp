#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    const int N = 1000000;

    // 质数筛
    vector<bool> st(N + 1, false);
    vector<vector<int>> hash(3);
    for(int i = 2; i <= N; ++ i)
    {
        if(st[i]) continue;

        // 保存其2,3,4次方值
        long long val = i;
        for(int j = 2; j <= 4; ++ j)
        {
            val *= i;
            if(val > N)
                break;
            hash[j - 2].push_back(val);
        }

        // 筛
        for(int j = 2; j * i <= N; ++ j)
            st[i * j] = true;
    }

    // 判断是否构成合法表达式
    vector<int> preSum(N + 1, 0);
    int cnt = 0;
    for(auto x : hash[0])
        for(auto y : hash[1])
        {
            if(x + y >= N)
                break;
            for(auto z : hash[2])
            {
                int val = x + y + z;
                if(val > N)
                    break;
                preSum[val] = 1; // 可能存在多个组合构成的值相同的情况，只保留一种
            }
        }
    // 前缀和
    for(int i = 2; i <= N; ++ i) 
        preSum[i] += preSum[i - 1];

    int t;
    cin >> t;
    while(t -- )
    {
        int n;
        cin >> n;
        cout << preSum[n] << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")