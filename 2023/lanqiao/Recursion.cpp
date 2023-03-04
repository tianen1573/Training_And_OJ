
//yxc

/*
* 开关的先后顺序不影响最终状态，则我们先确定第一行的状态，再去确定下一行的状态，递推所有行
*/


#include<iostream>
#include<cstring>

using namespace std;

const int N = 6;

char g[N][N], bg[N][N];
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};

void turn(int x, int y)  // 按一下第x行第y列的开关
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
        
        //模拟第一行是否按开关，递推剩下四行状态
        //五个字符根据是否按开关共有32种状态，用二进制模拟
        for(int op = 0; op < 32; op ++)
        {
            int cnt = 0;
            memcpy(g, bg, sizeof g);
            
            //移位获取对应位置开关是否需要按
            for(int j = 0; j < 5; ++ j)
            {
                if(op >> j & 1)
                {
                    turn(0, j);
                    cnt ++;
                }
            }
            
            //当前开关若是0，因为本行的灯不能再按，则其下面的灯必须按，否则一定不能按
            for(int r = 0; r < 4; ++ r)
                for(int c = 0; c < 5; ++ c)
                    if(g[r][c] == '0')
                    {
                        turn(r + 1, c);
                        cnt ++;
                    }
            
            //只需要判断最后一行的状态
            bool success = true;
            for(int c = 0; c < 5; ++ c)
                if(g[4][c] == '0')
                    success = false;
            
            //取小值
            if(success && res > cnt) res = cnt;
            
        }
        
        if(res > 6) res = -1;
        printf("%d\n", res);
    }
    
    
    return 0;
}