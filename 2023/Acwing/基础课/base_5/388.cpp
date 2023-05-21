
#include <cstdio>
#include <iostream>

using namespace std;

/* <p>
*   -若 d<x，则前三位的取值范围为 000∼abc−1，后三位的取值范围为 000∼999，这样合法的数就有 abc⋅1000 个
*   -若 d=x
*     -前三位取 000∼abc−1，后三位取 000∼999，这样合法的数就有 abc⋅1000 个
*     -前三位取 abc，后三位取 000∼efg，这样合法的数就有 efg+1 个
*   -若 d>x，则前三位取 000∼abc，后三位取 000∼999，这样合法的数有 (abc+1)⋅1000
* 每一位都像这样讨论，就可以算出来所有合法的数的个数。
* <p>
*/
int countDigitVal(int n, int x)
{
    int dig = 1, res = 0;
    int high = n / 10, cur = n % 10, low = 0;
    
    //0需要特判，应为当cur==0时，不允许high为0
    if(x == 0)
    {
        while(high != 0 || cur != 0)
        {
            if(cur == x && high) 
            {
                res += (high - 1) * dig + low + 1;
            }
            else if(cur > x) res += (high * dig);
            
            low += cur * dig;
            cur = high % 10;
            high /= 10;
            dig *= 10;
        }
    }
    
    else
    {
        while(high != 0 || cur != 0)
        {
            if(cur == x) res += (high * dig + low + 1);
            else if(cur > x) res += ((high + 1) * dig);
            else res += (high * dig);
            
            low += cur * dig;
            cur = high % 10;
            high /= 10;
            dig *= 10;
        }
    }
    
    
    return res;
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int a, b;
    
    while(cin >> a >> b)
    {
        if(a == b && a == 0) break;
        
        if(a > b) swap(a, b);
        
        for(int i = 0; i < 10; ++ i)
            cout << (countDigitVal(b, i) - countDigitVal(a - 1, i)) << ' ';
            
        
        cout << endl;
    }
    
    // cout << countDigitVal(0,0) << ' ' << countDigitVal(10, 0);
    
    return 0;
    
}