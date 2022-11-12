// 小易经常沉迷于网络游戏.有一次,他在玩一个打怪升级的游戏,他的角色的初始能力值为 a.
// 在接下来的一段时间内,他将会依次遇见n个怪物,每个怪物的防御力为b1, b2,b3...bn.
// 如果遇到的怪物防御力bi小于等于小易的当前能力值c,
// 那么他就能粹轻松打败怪物,并且使得自己的能力值增加bi;
// 如果bi大于c,那他也能打败怪物,但他的能力值只能增加bi 与c的最大公约数.
// 那么问题来了,在一系列的锻炼后,小易的最终能力值为多少?
// https://www.nowcoder.com/questionTerminal/fe6c73cb899c4fe1bdd773f8d3b42c3d

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b > a)
        return gcd(b, a);
    else
    {
        if(a % b == 0)
        {
            return b;
        }
        else
        {
            return gcd(b, a % b);
        }
    }
}

int main()
{
    int cur = 0, n = 0;
    while(cin >> n >> cur)
    {
        int tmp = 0;
        while(n --)
        {
            cin >> tmp;
            if(cur >= tmp)
            {
                cur += tmp;
            }
            else

            {
                cur += gcd(tmp, cur);
            }
        }

        cout << cur << endl;
    }
    
    return 0;


}