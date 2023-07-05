#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int T; cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        string str; cin >> str;
        
        int k_cnt = 0, res = 0;
        
        if(str.size() < 9)
        {
            printf("Case #%d: 0\n", t);
            continue;
        }
        
        if(str[0] == 'K' && str[1] == 'I' && str[2] == 'C' && str[3] == 'K') ++ k_cnt;
        for(int i = 4; i < str.size(); ++ i)
        {
            if(str[i - 3] == 'K' && str[i - 2] == 'I' && str[i - 1] == 'C' && str[i] == 'K') 
                ++ k_cnt;
            else if(str[i - 4] == 'S' && str[i - 3] == 'T' && str[i - 2] == 'A' && str[i - 1] == 'R' && str[i] == 'T')
                res += k_cnt;
        }
        
        printf("Case #%d: %d\n", t, res);
        
    }
    
    return 0;
}