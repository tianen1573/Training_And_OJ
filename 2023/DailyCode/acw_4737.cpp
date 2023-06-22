#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int T, n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        int x, y;
        vector<double> red, yell;
        
        int rs, rh; cin >> rs >> rh;
        double sh = (rs + rh);

        cin >> n;
        for(int i = 1; i <= n; ++ i)
        {
            cin >> x >> y;
            double xy = sqrt(x * x + y * y);
            if(xy <= sh) red.push_back(xy);
        }
        cin >> m;
        for(int i = 1; i <= m; ++ i)
        {
            cin >> x >> y;
            double xy = sqrt(x * x + y * y);
            if(xy <= sh) yell.push_back(xy);
        }
        
        if(red.empty() || yell.empty())
        {
            printf("Case #%d: %d %d\n", t, red.size(), yell.size());
            
            continue;
        }
        
        sort(red.begin(), red.end());
        sort(yell.begin(), yell.end());
        
        int rp = 0, yp = 0;
        for(auto rv : red)
        {
            if(rv <= yell[0]) ++ rp;
            else break;
        }
        for(auto yv : yell)
        {
            if(yv <= red[0]) ++ yp;
            else break;
        }
        printf("Case #%d: %d %d\n", t, rp, yp);
    }
    
    return 0;
}