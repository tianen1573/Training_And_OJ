#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int h[N], e[N * 2], ne[N * 2], idx; // 邻接表
int color[N];

int n, m;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool dfs(int u, int c)
{
    color[u] = c;//染色
    
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];//取值
        if(!color[j])//如果该点还未染色
        {
            //给该点染色，并扩展到该块的所有点
            if(!dfs(j, 3 - c)) return false;
        }
        else if(color[j] == c) return false;//染过色了，并且和当前节点冲突
    }
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    while(m --)
    {
        int a, b; cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    
    bool flag = true;
    //为什么在外面，需要对所有节点遍历一次？ 
    //因为没有明确说图只有一个连通块， 多个连通块构成一个图时， 就需要遍历所有节点，确保所有连通块都被遍历过
    for(int i = 1; i <= n; ++ i)
    {
        //如果该点还没有被染色
        if(!color[i])
        {
            //则给它染色， 并且扩展到其所在的块中的其他点染色
            if(!dfs(i, 1))//存在矛盾
            {
                flag = false;
                break;
            }
        }
    }
    
    if(flag) cout << "Yes";
    else cout << "No";
    
    return 0;
}