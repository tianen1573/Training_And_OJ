#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100010;

int arr[N], q[N];//q数组存储的是，序列长度为i时，最小的结尾元素

int n;


/*
i代表序列长度，q[i]存的是长度为i的序列，最小的结尾值
则   序列长度大的结尾值 必定大于 序列长度小的结尾值

看题解
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> arr[i];
    q[0] = -2 * 1e9;
    
    int len = 0;//len代表队列长度，也代表当前最大上升子序列的长度
    for(int i = 1; i <= n; ++ i)
    {
        int l = 0, r = len;
        
        //找到最后一个比arr[i]小的序列
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(q[mid] < arr[i]) l = mid;
            else r = mid - 1;
        }
        
        len = max(len, r + 1);//如果是最好一个序列，即r==len时，len就需要更新
        
        //arr[i] > q[r], 将其添加到q[i]后面，长度就变成了r+1， 并且可以保证q[r+1] > arr[i]
        //则r+1序列据需要更新结尾
        q[r + 1] = arr[i];
    }
    
    
    cout << len;
    
    return 0;
}