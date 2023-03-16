
//https://www.nowcoder.com/questionTerminal/3549ff22ae2c4da4890e9ad0ccb6150d

#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    long long sum[81] = {0, 1};
    for(int i = 2; i <= 80; ++ i) sum[i] = sum[i - 1] + sum[i - 2];
    for(int i = 1; i <= 80; ++ i) sum[i] += sum[ i - 1];
    int l, r;
    
    while(cin >> l >> r)
    {
        long long ans = sum[r] - sum[l - 1];
        cout << ans << endl;
        //cout << sum[80];
    }
    
    return 0;
}