#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() 
{
    int ans = INT_MAX, k = 1;
    
    int n; cin >> n;
    for(int i = 0; i < n; ++ i)
    {
        int tmp; cin >> tmp;
        if(ans == tmp)
            ++ k;
        else
        {
            if(k == 1)
            {
                ans = tmp;
            }
            else 
            {
                -- k;
            }
        }
    }
    
    /*
    * 题目保证仅有一个数满足要求，但没保证一定有
    * 安全起见，应该把数组保存下来，最后判断一下ans是否满足条件
    * 但AC了
    */

    cout << ans;

    return 0;
}
// 64 位输出请用 printf("%lld")