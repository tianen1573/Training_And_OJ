#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

const int N = 1000009;

char s[N], p[N];
// string s, p;
int ne[N];

int main()
{
    int n, m;
    scanf("%d%s%d%s", &n, p+1, &m, s+1);//下标从1开始
    
   // i = 2, 因为第一个字符匹配失败后，仍然从它开始，不需要设置，就是0
   // j代表的是，已经通过匹配的字符的下标，0代表没有字符匹配
   // 而且，当前ne最多比上一个多一，当前字符结尾能找到前缀，一定代表上一个字符能找到前缀
    for(int i = 2, j = 0; i <= n; ++ i)
    {
           //j存在，并且进行套娃
        while(j && p[i] != p[j + 1]) j = ne[j];
        
        if(p[i] == p[j + 1]) ++ j;
        
        ne[i] = j;
    }
    
    for(int i = 1, j = 0; i <= m; ++ i)
    {
        //套娃
        while(j && s[i] != p[j + 1]) j = ne[j];
        
        if(s[i] == p[j + 1]) ++ j;
        
        if(j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }
    
    return 0;
}

// int main()
// {
//     int n, m;
//     cin >> n >> p >> m >> s;
//     for(int i = 1, j = 0; i < n; ++ i)
//     {
//         while(j && p[i] != p[j]) j = ne[j];
        
//         if(p[i] == p[j]) ++ j;
        
//         ne[i] = j;
//     }
//     for(int i = 0, j = 0; i < m; ++ i)
//     {
//         while(j && s[i] != p[j]) j = ne[j];
//         if(s[i] == p[j]) ++ j;
//         if(j == n)
//         {
//             cout << i - n + 1 << ' ';
//             j = ne[j - 1];
//         }
//     }
    
//     return 0;
// }