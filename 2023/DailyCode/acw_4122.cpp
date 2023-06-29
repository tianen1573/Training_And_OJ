#include <iostream>
#include <cstring>

using namespace std;


int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        string s; cin >> s;
        string f; cin >> f;
        char st[26] = {0};
        for(auto ch : f) st[ch - 'a'] = true;
        
        int res = 0;
        for(char ch : s)
        {
            int cnt = 0;
            int left = ch - 'a', rig = ch - 'a';//往左右走
            while(!st[left] && !st[rig])
            {
                ++ cnt;
                left = (left - 1 + 26) % 26;
                rig = (rig + 1) % 26;
            }
            res += cnt;
        }
        
        printf("Case #%d: %d\n", t, res);
    }
    
    return 0;
}