#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int arr[N], hsize;

void down(int parent)//迭代更好
{
    int child = parent * 2;
    if(child > hsize) return ;//没有左孩子
    if((child + 1 <= hsize) && arr[child] > arr[child + 1]) child ++;//有右孩子，找最小的那个
    if(arr[parent] < arr[child]) return ;//是否需要交互
    
    swap(arr[parent], arr[child]);
    parent = child;
    
    down(parent);
}

void up(int child)
{
    if(child == 0) return ;
    
    int parent = child / 2;
    
    if(arr[child] >= arr[parent]) return ;//是否需要交换
    
    swap(arr[child], arr[parent]);
    child = parent;
    
    up(child);
}

int main()
{
    hsize = 0;
    scanf("%d%d",&n ,&m);
    for(int i = 1; i <= n; ++ i) scanf("%d", &arr[i]);
    hsize = n;
    
    for(int i = hsize / 2; i > 0; -- i)
        down(i);
    
    
    while(m -- )
    {
        printf("%d ", arr[1]);
        swap(arr[1], arr[hsize]);
        hsize --;
        down(1);
    }
    
    return 0;
}