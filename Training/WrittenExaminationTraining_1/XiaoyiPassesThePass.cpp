// С�׾���������������Ϸ.��һ��,������һ�������������Ϸ,���Ľ�ɫ�ĳ�ʼ����ֵΪ a.
// �ڽ�������һ��ʱ����,��������������n������,ÿ������ķ�����Ϊb1, b2,b3...bn.
// ��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,
// ��ô�����ܴ����ɴ�ܹ���,����ʹ���Լ�������ֵ����bi;
// ���bi����c,����Ҳ�ܴ�ܹ���,����������ֵֻ������bi ��c�����Լ��.
// ��ô��������,��һϵ�еĶ�����,С�׵���������ֵΪ����?
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