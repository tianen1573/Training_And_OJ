// 输入一个正整数，计算它在二进制下的1的个数。注意多组输入输出!!!! ! !

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