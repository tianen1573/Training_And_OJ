#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int arr[101];
int n = 100;
int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
set<int> iset;

void check(int month, int day)
{
    if(month < 1 || month > 12 || day < 1 || day > days[month]) return ;
    iset.insert(month * 100 + day);
}

int main()
{
    for(int i = 1; i <= n; ++ i)
        cin >> arr[i];
    
    for(int a = 1; a <= n; ++ a)
    {
        if(arr[a] != 2) continue;
        for(int b = a + 1; b <= n; ++ b)
        {
            if(arr[b] != 0) continue;
            for(int c = b + 1; c <= n; ++ c)
            {
                if(arr[c] != 2) continue;
                for(int d = c + 1; d <= n; ++ d)
                {
                    if(arr[d] != 3) continue;

                    for(int i = d + 1; i <= n; ++ i)
                    for(int j = i + 1; j <= n; ++ j)
                    for(int k = j + 1; k <= n; ++ k)
                    for(int l = k + 1; l <= n; ++ l)
                        check(arr[i] * 10 + arr[j], arr[k] * 10 + arr[l]);
                }
            }
        }
    }

    cout << iset.size();

    return 0;
}