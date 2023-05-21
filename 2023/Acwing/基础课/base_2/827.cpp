#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100009;

int e[N], l[N], r[N], head, tail, idx;

void init()
{
    head = -1;
    tail = -1;
    idx = 1;
}

void pushBack(int val)
{
    if(head == -1 || tail == -1)
    {
        head = idx;
        tail = idx;
    }
    
    e[idx] = val;
    
    r[tail] = idx;
    l[head] = idx;
    
    l[idx] = tail;
    r[idx] = head;
    
    tail = idx ++ ;
}
void pushFront(int val)
{
    
    if(head == -1 || tail == -1)
    {
        head = idx;
        tail = idx;
    }
    
    e[idx] = val;
    
    l[head] = idx;
    r[tail] = idx;
    
    l[idx] = tail;
    r[idx] = head;
    
    head = idx ++;
    
}

void delPos(int k)
{
    if(l[k] == k && r[k] == k)
    {
        head = -1;
        tail = -1;
        
        return ;
    }
    
    r[l[k]] = r[k];
    l[r[k]] = l[k];
    
    if(k == head) head = r[k];
    if(k == tail) tail = l[k];
    
}

void insertLeftPos(int k, int val)
{
    e[idx] = val;
    
    r[l[k]] = idx;
    l[idx] = l[k];
    
    r[idx] = k;
    l[k] = idx;
    
    if(head == k) head = idx;
    
    ++ idx;
    
}
void insertRigPos(int k, int val)
{
    e[idx] = val;
    
    l[r[k]] = idx;
    r[idx] = r[k];
    
    l[idx] = k;
    r[k] = idx;
    
    if(tail == k) tail = idx;
    
    ++ idx;
}

int main()
{
    int m; cin >> m;
    
    
    init();
    while(m --)
    {
        string op;
        int k, x;
        
        cin >> op;
        if(op == "L")
        {
            scanf("%d", &x);
            pushFront(x);
        }
        else if(op == "R")
        {
            scanf("%d", &x);
            pushBack(x);
        }
        else if(op == "D")
        {
            scanf("%d", &k);
            delPos(k);
        }
        else if(op == "IL")
        {
            scanf("%d%d", &k, &x);
            insertLeftPos(k, x);
        }
        else
        {
            scanf("%d%d", &k, &x);
            insertRigPos(k, x);
        }
        
        // int i = head;
        // for(; i != tail; i = r[i])
        //     printf("%d ", e[i]);
        // printf("%d\n", e[i]);
    }
    
    int i = head;
    for(; i != tail; i = r[i])
        printf("%d ", e[i]);
    printf("%d", e[i]);
    
    return 0;
}