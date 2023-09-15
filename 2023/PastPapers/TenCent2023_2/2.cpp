// 小Q有一个长度为n的数组，它对这个数组有k次操作机会，操作如下:可以选择数组中的任意一个数字并改变它
// 1.如果选择的数字x是奇数，那么这个奇数乘以2，即x=x*2
// 2.如果选择的数字x是偶数，那么这个偶数乘以2再加1，即x=x*2+1
// 小Q想让这k次操作之后，数组元素之和最小，请你输出这个最小值是多少?保证最终的元素之和不超过10^18


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    long long sum = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pque;
    
    for(int i = 0; i < n; ++ i)
    {
        int val; cin >> val;
        sum += val;
        pque.push(val);
    }
    while(k --)
    {
        auto val = pque.top();
        pque.pop();
        
        if(val & 1)
        {
            sum += val;
            pque.emplace(val * 2);
        }
        else
        {
            sum += val + 1;
            pque.emplace(val * 2 + 1);
        }
    }
    
    cout << sum;
    
    return 0;
}
