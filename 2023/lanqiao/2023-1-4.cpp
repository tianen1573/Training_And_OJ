#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Val
{
    int ti, di, li;

}edges[13];
bool st[13];

int t, n;

bool dfs(int cnt, int last_li)
{
    if(cnt == n) return true;

    for(int i = 1; i <= n; ++ i)
    {
        if(st[i]) continue;

        if(last_li <= edges[i].ti + edges[i].di)
        {
            st[i] = true;

            int new_li;
            if(last_li <= edges[i].ti) new_li = edges[i].ti + edges[i].li;
            else new_li = last_li + edges[i].li;

            if(dfs(cnt + 1, new_li)) return true;

            st[i] = false;
        }   
    }

    return false;
}

int main()
{
    cin >> t;
    
    while( t --)
    {
        memset(st, 0, sizeof st);

        cin >> n;
        for(int i = 1; i <= n; ++ i)
        {
            cin >> edges[i].ti >> edges[i].di >> edges[i].li;

        }

        bool flag = true;

        for(int i = 1; flag && i <= n; ++ i)
        {
            st[i] = true;
            if(dfs(1, edges[i].li + edges[i].ti)) flag = false;
            st[i] = false;
        }
        
        if(flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }


    return 0;
}