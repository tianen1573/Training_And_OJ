
/*����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int m, n;
    char arr[] = "0123456789ABCDEF";
    int sta = 1;
    
    cin >> m >> n;
    
    //�ж�����
    if(m < 0)
    {
        m *= -1;
        sta = -1;
    }
    
    string res = "";
    
    while(m)
    {
        res.push_back(arr[m % n]);
        m /= n;
    }
    
    reverse(res.begin(), res.end());
    if(res == "")//�ж�0
    {
        res = "0";
    }    
    if(sta == -1)//�ж�����
    {
        res.insert(res.begin(), '-');
    }
    
    cout << res;
    
    return 0;
}