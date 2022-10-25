

// С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ:1��2��3.......
// ����ʯ��·Ҫ��������Ĺ������ǰ��:����С�׵�ǰ���ڵı��ΪK��ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����
// ������K+��(XΪK��һ����1�ͱ����Լ��)��λ�á�С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��
// С����֪��������Ҫ��Ծ���ο��Ե��
// ����:
// N= 4��M= 24:4->6->8->12->18->24
// ����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��

// ��̬�滮

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

int dp[100011];

int main() {
    int n, m;
    cin >> n >> m;

    //memset(dp, 0x3f, sizeof(int) * (m + 1));
    //cout << dp[0];

    dp[n] = 1;
    for (int i = n; i < m; ++i) {
        if (dp[i]) 
        {
            for (int j = 2; j <= sqrt(i); j ++) //����ƽ�����ɹ��� ����2 ����
            {
                if (i % j == 0) {
                    int ij = i / j;
                    
                    if (i + j <= m)
                    {
                        dp[i + j] = dp[i + j] ? min(dp[i + j], dp[i] + 1) : dp[i] + 1;
                    }
                        
                    if (i + ij <= m)
                    {
                        dp[i + ij] = dp[i + ij] ? min(dp[i + ij], dp[i] + 1) : dp[i] + 1;
                    }
                }
            }
        }
    }
    if (dp[m] == 0)
        cout << "-1";
    else
        cout << dp[m] - 1;

    return 0;
}