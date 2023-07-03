#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        bool flag = true;
        long long n, d, c, m;
        string que;
        cin >> n >> d >> c >> m >> que;
        
        int i = 0;
        for( ; i < n; ++ i)
        {
            //先判断狗猫
            if('C' == que[i])
            {
                -- c;
            }
            else if('D' == que[i])
            {
                -- d;
                c += m;
            }
            
            //再判断食物
            if(c < 0 || d <= 0)
            {
                if(d < 0)//狗粮为负，代表当前这只狗就没得吃
                {
                    flag = false;
                    break;
                }
                
                //猫粮为负，代表当前猫没得吃， 看后续是否还有狗
                //狗粮为零，代表狗粮吃完了，看后续是否还有狗
                //只要有，后边的狗就没得吃
                int pos = que.find('D', i + 1);
                if(pos == -1)
                {
                    break;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag) printf("Case #%d: YES\n", t);
        else printf("Case #%d: NO\n", t);
    }
    
    return 0;
}