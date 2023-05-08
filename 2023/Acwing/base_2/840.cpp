// //开散列
// #include <cstdio>
// #include <iostream>
// #include <cstring>
// using namespace std;

// const int N = 100009;

// int h[N], e[N], ne[N], idx;//h[]：桶，e[]：存值， ne[]：存索引

// void insert(int x)
// {
//     int k = (x % N + N) % N;
    
//     //头插法
//     e[idx] = x;
//     ne[idx] = h[k];
//     h[k] = idx ++;
// }
// bool find(int x)
// {
//     int k = (x % N + N) % N;
    
//     for(int i = h[k]; i != -1; i = ne[i])
//         if(e[i] == x) return true;
        
//     return false;
// }

// int main()
// {
//     int n; scanf("%d", &n);
    
//     memset(h, -1, sizeof h);//初始化h数组全为-1，-1的补码全是1
//     while( n --)
//     {
//         char op[2];
//         int x;
//         scanf("%s%d", op, &x);
        
//         if(*op == 'I')
//             insert(x);
//         else
//         {
//             if(find(x)) printf("Yes\n");
//             else printf("No\n");
//         }
            
//     }
    
//     return 0;
// }


//闭散列
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 200097, nul = 0x3f3f3f3f;

int h[N];


//返回下标，当插入时，返回x应该在的节点的下标； 当查询时，h[ret] == val 判断是否存在
int find(int x)
{
    int k = (x % N + N) % N;//存在负数
    
    //h[k] != nul，非空节点
    //h[k] != x : 查询时使用
    while(h[k] != nul && h[k] != x)
    {
        k = (k + 1) % N;
    }
    
    return k;
}

int main()
{
    int n; scanf("%d", &n);
    
    memset(h, 0x3f, sizeof h);
    
    while( n --)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        
        if(*op == 'I')
            h[find(x)] = x;
        else
        {
            if(h[find(x)] != nul) printf("Yes\n");
            else printf("No\n");
        }
            
    }
    
    return 0;
}