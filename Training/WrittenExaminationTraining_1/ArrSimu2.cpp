
/*������� ���ϸ���� �� ���ϸ�ݼ� ������������ ����С����*/

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
        //���ϸ�����
        else if(arr[i] > arr[i - 1])
        {
            while(i < n && arr[i] >= arr[i - 1])
            {
                ++i;
            }
            res++;
        }
        //���ϸ���
        else
        {      
            while(i < n && arr[i] <= arr[i - 1])
            {
                ++i;
            }
            res++;         
        }
        //���ֻʣ���һ��Ԫ�أ� �����Գ�һ������
        if(i == n - 1) res++;
    }
    
    if(res == 0) res++;
    
    
    cout << res;
    
    return 0;
}