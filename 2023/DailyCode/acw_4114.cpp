#include <iostream>
#include <cstring>

using namespace std;

//1. 可以记录垃圾桶的位置，进行二分查找
//2. 遍历记录最左最右，每次只需要遍历到左边房子的最近位置，右边同理

const int N = 5 * 1e5 + 11;

int l[N], r[N];
int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int T; cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        // memset(l, 0x3f, sizeof l);
        // memset(r, 0x3f, sizeof r);
        
        int n;
        string str;
        cin >> n >> str;
        int left = 0x3f3f3f3f, rig = 0x3f3f3f3f;
        for(int i = 0, j = n - 1; i < n; ++ i, -- j)
        {
            if(str[i] == '1')
                left = 0;
            else
                ++ left;
            if(str[j] == '1')
                rig = 0;
            else
                ++ rig;
            l[i] = left;
            r[j] = rig;
        }
        long long res = 0;
        for(int i = 0; i < n; ++ i)
        {
            // cout << " " << l[i] << " " << r[i] << endl;
            res += min(l[i], r[i]);
        }
        
    
        printf("Case #%d: %lld\n", t, res);
    }
    
    return 0;
}