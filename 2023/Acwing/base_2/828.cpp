#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100009;

int stk[N];
int top;

void init()
{
    top = 0;
}
void push(int val)
{
    stk[top ++] = val;
}
void pop()
{
    top --;
}
bool empty()
{
    return top == 0; 
}
int query()
{
    return stk[top - 1];
}

int main()
{
    int m; scanf("%d", &m);
    
    
    init();
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
            int topV = query();
            printf("%d\n", topV);
        }
    }
    
    
    return 0;
}