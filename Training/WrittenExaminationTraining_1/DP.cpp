
/*
һ��������N��Ԫ�أ�����������������͡�����:[-1,2,1]������������������Ϊ[2,1]�����Ϊ3

: ������ĳ�±�Ԫ�ؽ�β���ִ� ������
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