

/*
* 给你一组数据，3 * n 个元素， 请你分配成n个元组， 每个元组满足 a < b < c
* 且元组的值 为 b
* 求元组和最大分配
*/

/*
推理得：
 排序后， 最小的前n个元素最为a， 剩下的两个为一组， 第一个为b， 和最大
证明： 无
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
    int n = 0;
    cin >> n;
    
    vector<int> arr(n * 3);
    
    for(int i = 0; i < 3 * n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    unsigned long long res = 0;
    
    for(int i = n; i < 3 * n; i += 2)
    {
        res += arr[i];
    }
    
    cout << res;
    
    return 0;
}