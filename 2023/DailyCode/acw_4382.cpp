#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int t; cin >> t;
    
    for(int i = 1; i <= t; ++ i)
    {
        string a, b;
        cin >> a >> b;
        
        if(a.size() > b.size())
        {
            printf("Case #%d: IMPOSSIBLE\n", i);
            continue;
        }
        
        int cnt = 0;
        bool flag = true;
        int p1 = 0, p2 = 0;
        for(; p1 < a.size(); ++ p1, ++ p2)
        {
            while(p2 < b.size() && b[p2] != a[p1])
            {
                ++ cnt;
                ++ p2;
            }
            if(p2 == b.size())
            {
                flag = false;
                printf("Case #%d: IMPOSSIBLE\n", i);
                break;
            }
        }
        cnt += (b.size() - p2);
        if(flag) printf("Case #%d: %d\n", i, cnt);
    }
    
    
    return 0;
}