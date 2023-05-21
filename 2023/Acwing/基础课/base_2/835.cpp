#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100009;

int son[N][26] = {0};
int cnt[N] = {0};
char str[N];
int idx;

//把所有字符串看成树，则每个节点代表的是，多个字符串的相同位置且相同的字符
//上述这些“节点”具有独立的编号，在第一次出现时分配，即idx
//cnt：所有不重复的字符串的每个结束字符，都要有其独立的计数

void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; ++ i)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++ idx;//第一次出现分配编号，从一开始
        p = son[p][u];
    }
    
    cnt[p] ++ ;
}
int query(char str[])
{
    
    int p = 0;
    for(int i = 0; str[i]; ++ i)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    
    //此时p是该字符的结束字符所在节点的编号
    return cnt[p];
}

int main()
{
    int n; scanf("%d", &n);
    
    while(n --)
    {
        char op[2];
        scanf("%s%s", op, str);
        if(*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }
    return 0;
}