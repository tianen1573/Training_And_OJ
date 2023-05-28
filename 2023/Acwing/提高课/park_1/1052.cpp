//f[i][j]: 构建的密码长度为i时，且后缀与模式串匹配的最大长度为j 的 总方案数
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 53, MOD = 1e9 + 7;

int f[N][N];

int ne[N];
char s[N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> s + 1;
    
    int m = strlen(s + 1);
    
    //处理下模式串s
    for(int i = 2, j = 0; i <= m; ++ i)
    {
        while(j && s[i] != s[j + 1]) j = ne[j];
        
        if(s[i] == s[j + 1]) ++ j;
        
        ne[i] = j;
    }
    
    f[0][0] = 1;
    for(int i = 0; i < n; ++ i)//构建密码， i+1 为密码长度
        for(int j = 0; j < m; ++ j)//模拟最大后缀匹配长度
            for(char ch = 'a'; ch <= 'z'; ++ ch)//枚举第 i+1 字符
            {
                int ptr = j;//ptr: 转移后的最大长度
                
                //求由f[i][j] 能够转移到的 f[i+1][ptr]状态
                while(ptr && s[ptr + 1] != ch) ptr = ne[ptr];
                if(ch == s[ptr + 1]) ptr++;
                
                f[i + 1][ptr] = (f[i + 1][ptr] + f[i][j]) % MOD;
            }
    
    int res = 0;
    for(int i = 0; i < m; ++ i)
        res = (res + f[n][i]) % MOD;
    cout << res;
    
    return 0;
}
