#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        vector<int> arr;
        string str;
        int n;
        cin >> n >> str;
        
        char last = 'a';
        int cnt = 1;
        
        printf("Case #%d:", t);
        for(int i = 0; i < n; ++ i)
        {
            if(str[i] > last)
                ++ cnt;
            else
                cnt = 1;
            
            last = str[i];
            
            printf(" %d", cnt);
        }
        printf("\n");
    }
    
    return 0;
}