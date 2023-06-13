#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

LL cnt, leftt;//leftt为当前草料可以吃到的日子，cnt为没有草料吃的日子数
LL n, t;

int main()
{
    
    cin >> n >> t;
    
    for(int i = 1; i <= n; ++ i)
    {
        LL d, b; cin >> d >> b;
        if(leftt >= t) continue;
        
        if(d <= leftt)//如果日期为d时，还有草料吃，则顺延
        {
            leftt += b;
        }
        else//没有的吃，则统计没吃的日子数，并更新这次能吃到什么时候
        {
            cnt +=(d - leftt - 1);
            leftt = d + b - 1;
        }
    }
    
    cnt += max((LL)0, (t - leftt));//判断是否吃到了日期t
    
    cout << t - cnt;
}