
//https://www.nowcoder.com/questionTerminal/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, cnt = 0;
        cin >> n >> cnt;
        vector<int> vec(n * 2);
        for(int i = 0; i < 2 * n; ++ i)
        {
            cin >> vec[i];
        }
        
        while(cnt --)
        {
            vector<int> tmp(n * 2);
            for(int i = 0, j = 0; i < n; ++ i, ++ j)
            {
                tmp[i + j] = vec[i];
            }
            for(int i = n, j = n - 1; i < 2 * n; ++ i, -- j)
            {
                tmp[i - j] = vec[i];
            }
            
            vec = tmp;
        }
        
        for(auto& x : vec)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    
    return 0;
}