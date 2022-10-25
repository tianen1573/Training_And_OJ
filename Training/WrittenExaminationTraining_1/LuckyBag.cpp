
// 一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。
// 如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
// 例如:如果袋子里面的球的号码是{1,1,2,3}，这个袋子就是幸运的，因为1+1+2+3>1*1* 2* 3
// 你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。
// 现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。


/* https://www.nowcoder.com/questionTerminal/a5190a7c3ec045ce9273beebdfe029ee */

// a + b > a * b, 则至少一个为1， 且不能同时为1
// 若 sum <= pro, 则 新增的球只能为1， 才有可能 满足 sumNew > proNew
// 不妨先把 所有的1 组合起来作为最底层， 则剩下的球全是大于1的
// 那么 sumNew < proNew 时， 可直接将这个组合舍弃， 因为不存在新的1，不会使这个组合变得幸运

#include<iostream>
#include<map>
using namespace std;

#define x first
#define y second

typedef long long LL;
typedef pair<int, long long > pil;

map<int, int> mvc;
map<pil, int> spc, tmpM;

int main()
{
    int n = 0;
    cin >> n;
    
    //统计号码的个数
    for(int i = 0; i < n; ++ i)
    {
        int tmp = 0;
        cin >> tmp;
        mvc[tmp]++;
    }
    
    //不存在1直接输出
    if(mvc[1] == 0)
    {
        cout << "0";
        return 0;
    }
    //先将1作为底层， 为后面舍弃不必要的组合做准备
    pil tmp = {1, 1};//{1，1}不幸运
    spc[tmp] += 1;
    long long res = 0;
    for(int i = 2; i <= mvc[1]; ++ i)
    {
        tmp.x += 1;
        tmp.y *= 1;
        
        ++res;//除了1个1， 都是幸运的

        spc[tmp] += 1;
    }
    mvc.erase(1);
    
    for(auto num : mvc)//球的 号码 和 个数
    {  
        //与之前的组合
        tmpM = spc;//当前变化可能会影响后序的操作， 拷贝一份
        for(auto& val : tmpM)//袋子 的 和积 与 个数
        {
            tmp = val.x;
            for(int i = 1; i <= num.y; ++ i)
            {
                tmp.x += num.x;
                tmp.y *= num.x;

                if(tmp.x > tmp.y)
                {
                    res += val.y;
                    spc[tmp] += val.y;
                }
                else//不存在号码1， 就 无法使不幸运组合 变 幸运
                {
                    break;
                }
    
            }
        }
    }
    
    cout << res;
    return 0;
}