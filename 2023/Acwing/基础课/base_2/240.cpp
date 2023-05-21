#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

/*
区域：两个动物交互过，才在同一个种群，否则为不同的祖宗节点，而且对一个第一次出现的动物，任何操作都是合法的
种群：同一种动物
%3：只有三种动物，用和动态生成的根节点的距离，代表种类
*/

const int N = 50099;

int  p[N], d[N];


//祖宗节点相同，代表在同一个区域里
//mod3值相同，才代表是相同的种群
int find(int x)
{
    if(p[x] != x)
    {
        int t = find(p[x]);//记录祖宗节点
        //走到这里，该路径，没有进行路径压缩。路径压缩，就需要改变与祖宗节点的距离值
        //代表p[x]是需要被改变的，那么我们的d[x]就需要变成，x与p[x]的距离 + p[x]与祖宗节点的距离
        d[x] += d[p[x]];
        
        p[x] = t;//路径压缩
    }
    
    return p[x];
}

int main()
{
    
    int n, k; scanf("%d%d", &n, &k);
    
    for(int i = 1; i <= n; ++ i) p[i] = i;
    
    int res = 0;
    
    while(k --)
    {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        
        if(x > n || y > n) ++ res;
        else 
        {
            int px = find(x), py = find(y);
            if(t == 2)
            {
                
                //px == py：代表x，y在同一个区域，不用合并
                //d[x] - d[y] - 1) % 3 == 0; 代表d[x]同余(d[y]+1)，即x的等级在y后面(等级是个圈)
                if(px == py && (d[x] - d[y] - 1) % 3) ++ res;//同一个区域，两个动物等级不对
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                    //d[x]：x相对于px的距离
                    //d[px]：px相对于py的距离 -- d[x] + d[px] == x相对于py的距离
                    //d[y]：y相对于py的距离
                    //则d[x] + d[px] - d[y] = 1;//x吃y
                }
            }
            else
            {
                //px == py：代表x，y在同一个区域，不用合并
                //d[x] - d[y]) % 3 == 0，同余定理，代表x，y相对于该区域的第一个物种的距离是相同的
                if(px == py && (d[x] - d[y]) % 3) ++ res;//在同一个区域，但不同物种
                else if(px != py)//不在同一个区域，则其中至少一个是第一次出现的动物编号，对他的任何操作，都应该是合法的
                {
                    p[px] = py;//合并区域
                    d[px] = d[y] - d[x];//因为x，y是同类，则有d[x] + d[px] = d[y];d[y]是y到py的距离
                }
            }
            
        }
        
    }
    
    printf("%d", res);
    
    return 0;
}