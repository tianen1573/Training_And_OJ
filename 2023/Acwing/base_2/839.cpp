#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int n;
int arr[N], hp[N], ph[N], hsize, idx;//hp：存储的是下标为i的元素是第几次插入的，ph：存储的是第k次插入的元素在堆中的下标

void MySwap(int p1, int p2)
{
    swap(ph[hp[p1]], ph[hp[p2]]);//先修改第k次插入指向的元素的下标，元素没变，但下标变了
    swap(hp[p1], hp[p2]);//修改当前元素的指向
    swap(arr[p1], arr[p2]);//修改元素值
    
    // swap(hp[p1], hp[p2]);//修改当前元素的指向
    // swap(ph[hp[p2]], ph[hp[p1]]);//先修改第k次插入指向的元素的下标，元素没变，但下标变了
    // swap(arr[p1], arr[p2]);//修改元素值
}

void down(int parent)//迭代更好
{
    int child = parent * 2;
    if(child > hsize) return ;//没有左孩子
    if((child + 1 <= hsize) && arr[child] > arr[child + 1]) child ++;//有右孩子，找最小的那个
    if(arr[parent] < arr[child]) return ;//是否需要交互
    
    MySwap(parent, child);
    parent = child;
    
    down(parent);
}

void up(int child)
{
    if(child == 1) return ;
    
    int parent = child / 2;
    
    if(arr[child] >= arr[parent]) return ;//是否需要交换
    
    MySwap(parent, child);
    child = parent;
    
    up(child);
}

int main()
{
    hsize = 0;
    scanf("%d",&n);
    
    while(n -- )
    {
        string op;
        int k, x;
        
        cin >> op;
        if(op == "I")
        {
            scanf("%d", &x);
            
            arr[++ hsize] = x;
            ph[++ idx] = hsize;
            hp[hsize] = idx;
            
            up(hsize);
        }
        else if(op == "PM")
        {
            printf("%d\n", arr[1]);
        }
        else if(op == "DM")
        {
            MySwap(1, hsize);
            -- hsize;
            down(1);
        }
        else if(op == "D")
        {
            scanf("%d", &k);
            k = ph[k];//找第k次插入的元素，在堆中的下标
            MySwap(k, hsize);
            -- hsize;
            
            down(k), up(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];//找第k次插入的元素，在堆中的下标
            arr[k] = x;
            down(k), up(k);
        }
    }
    
    return 0;
}