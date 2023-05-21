#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int N = 100009;

int que[N];
int hh, tt;

void init()
{
    hh = tt = 0;
}
void push(int val)
{
    que[tt ++] = val;
}
void pop()
{
    ++ hh;
}
bool empty()
{
    return hh == tt;
}
int front()
{
    return que[hh];
}

int main()
{
    int m; scanf("%d", &m);
    
    while(m --)
    {
        string op;
        int val;
        
        cin >> op;
        
        if(op == "push")
        {
            scanf("%d", &val);
            push(val);
        }
        else if(op == "pop")
        {
            pop();
        }
        else if(op == "empty")
        {
            if(empty()) printf("YES\n");
            else printf("NO\n");
        }
        else
        {
            int val = front();
            printf("%d\n", val);
        }
    }
    
    return 0;
}