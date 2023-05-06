#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100009;

//e[i] ： i节点数值
//ne[i] : i节点的next节点的下标
//head : 头节点
//idx ： 待使用的节点
int e[N], ne[N], head, idx;

void init()
{
    head = -1;
    idx = 1;
    
}

void addToHead(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    ++ idx;
}
void addPosNext(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    ++ idx;
}
void delPosNext(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    scanf("%d", &m);
    
    init();
    while(m --)
    {
        int x, y;
        char op;
        getchar();//吃掉换行符
        scanf("%c", &op);
        
        if(op == 'H')//头插
        {
            scanf("%d", &x);
            addToHead(x);
        }
        else if(op == 'I')//定点插入
        {
            scanf("%d %d", &x, &y);
            addPosNext(x, y);
        }
        else//定点删除
        {
            scanf("%d", &x);
            if(x == 0) head = ne[head];
            else delPosNext(x);
        }
    }
    
    for(int i = head; i != -1; i = ne[i])
        printf("%d ", e[i]);
    
    return 0;
}