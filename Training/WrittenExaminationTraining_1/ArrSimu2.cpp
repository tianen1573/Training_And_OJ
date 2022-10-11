
/*求数组的 不严格递增 或 不严格递减 的连续子序列 的最小个数*/

#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    long long res = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == arr[i - 1]) continue;
        //不严格升序
        else if(arr[i] > arr[i - 1])
        {
            while(i < n && arr[i] >= arr[i - 1])
            {
                ++i;
            }
            res++;
        }
        //不严格降序
        else
        {      
            while(i < n && arr[i] <= arr[i - 1])
            {
                ++i;
            }
            res++;         
        }
        //如果只剩最后一个元素， 则其自成一个序列
        if(i == n - 1) res++;
    }
    
    if(res == 0) res++;
    
    
    cout << res;
    
    return 0;
}