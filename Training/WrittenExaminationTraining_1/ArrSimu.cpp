

/*
* ����һ�����ݣ�3 * n ��Ԫ�أ� ��������n��Ԫ�飬 ÿ��Ԫ������ a < b < c
* ��Ԫ���ֵ Ϊ b
* ��Ԫ���������
*/

/*
����ã�
 ����� ��С��ǰn��Ԫ����Ϊa�� ʣ�µ�����Ϊһ�飬 ��һ��Ϊb�� �����
֤���� ��
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