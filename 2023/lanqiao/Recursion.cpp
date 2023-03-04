
//yxc

/*
* ���ص��Ⱥ�˳��Ӱ������״̬����������ȷ����һ�е�״̬����ȥȷ����һ�е�״̬������������
*/


#include<iostream>
#include<cstring>

using namespace std;

const int N = 6;

char g[N][N], bg[N][N];
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};

void turn(int x, int y)  // ��һ�µ�x�е�y�еĿ���
{
    for (int i = 0; i < 5; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5) continue;
        g[a][b] ^= 1;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while(T --)
    {
        for(int i = 0; i < 5; ++ i) scanf("%s", bg[i]);
        
        int res = 10;
        
        //ģ���һ���Ƿ񰴿��أ�����ʣ������״̬
        //����ַ������Ƿ񰴿��ع���32��״̬���ö�����ģ��
        for(int op = 0; op < 32; op ++)
        {
            int cnt = 0;
            memcpy(g, bg, sizeof g);
            
            //��λ��ȡ��Ӧλ�ÿ����Ƿ���Ҫ��
            for(int j = 0; j < 5; ++ j)
            {
                if(op >> j & 1)
                {
                    turn(0, j);
                    cnt ++;
                }
            }
            
            //��ǰ��������0����Ϊ���еĵƲ����ٰ�����������ĵƱ��밴������һ�����ܰ�
            for(int r = 0; r < 4; ++ r)
                for(int c = 0; c < 5; ++ c)
                    if(g[r][c] == '0')
                    {
                        turn(r + 1, c);
                        cnt ++;
                    }
            
            //ֻ��Ҫ�ж����һ�е�״̬
            bool success = true;
            for(int c = 0; c < 5; ++ c)
                if(g[4][c] == '0')
                    success = false;
            
            //ȡСֵ
            if(success && res > cnt) res = cnt;
            
        }
        
        if(res > 6) res = -1;
        printf("%d\n", res);
    }
    
    
    return 0;
}