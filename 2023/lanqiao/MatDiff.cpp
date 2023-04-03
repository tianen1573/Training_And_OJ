#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int sub[1007][1007];

int n,m,q;

void insert(int x1, int y1, int x2, int y2, int val)
{
    sub[x1][y1] += val;
    sub[x2 + 1][y2 + 1] += val;
    sub[x2 + 1][y1] -= val;
    sub[x1][y2 + 1] -= val;
}

int main()
{
    int tmp;
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i ++ )
        for(int j = 1; j <= m; j ++ )
            {
                cin >> tmp;
                insert(i, j, i, j, tmp);
            }
        
    int x1, y1, x2, y2, val;    
    while(q -- )
    {
        cin >> x1 >> y1 >> x2 >> y2 >> val;
        insert(x1, y1, x2, y2, val);
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
         sub[i][j] += sub[i - 1][j] + sub[i][j - 1] - sub[i - 1][j - 1]; 
         
    for (int i = 1; i <= n; i ++ )
        {
            for(int j = 1; j <= m; j ++ )
                cout << sub[i][j] << " ";
            cout << endl;
        }
    return 0;
}