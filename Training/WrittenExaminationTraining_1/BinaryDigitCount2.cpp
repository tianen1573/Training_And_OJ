// ����һ�����������������ڶ������µ�1�ĸ�����ע������������!!!! ! !

#include<iostream>

using namespace std;

int main()
{
    int n = 0;
    while(cin >> n)
    {
        int cnt = 0;

        for(int i = 0; i < 32; ++ i)
        {
            if(n >> i & 1)
            {
                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}