#include <cstdio>
#include <iostream>

#include <stack>

using namespace std;

stack<int> stk;

int main()
{
    
    int n; scanf("%d", &n);
    
    while(n -- )
    {
        int val; scanf("%d", &val);
        
        while(!stk.empty() && stk.top() >= val) stk.pop();
        
        if(!stk.empty()) printf("%d ", stk.top());
        else printf("-1 ");
        
        stk.push(val);
    }
    
    return 0;
}