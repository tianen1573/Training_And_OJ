
/*
一个数组有N个元素，求连续子数组的最大和。例如:[-1,2,1]，和最大的连续子数组为[2,1]，其和为3

: 保留以某下标元素结尾的字串 的最大和
*/

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
    
    int res = arr[0];
    for(int i = 1; i < n; ++i)
    {
        arr[i] = max(arr[i] + arr[ i - 1], arr[i]);
        res = max(res, arr[i]);
    }
    
    cout << res;
    
    return 0;
}