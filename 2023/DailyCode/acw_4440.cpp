//1. 两个为一组，则反转只在组内翻转
//2. HH GG，就可以舍弃，只讨论组内为 HG GH 时，记为0，1
//3. 则我们需要把01字符串改造成全0字符串，一定可行
//4. 以i为结尾的前缀字符串元素是相同的，则 w[i] != w[i + 1]时，就需要翻转，翻转后所有元素都为w[i + 1];
//5. 则走到cnt时，所有元素都为w[cnt + 1] == 0, 此时res就为最小次数


#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 11;

int w[N], cnt = 0;
string str;

int n;

int main()
{
    cin >> n >> str;
    
    for(int i = 0; i <= str.size(); i += 2)
    {
        if(str[i] == 'H' && str[i + 1] == 'G')
            w[++ cnt] = 0;
        else if(str[i] == 'G' && str[i + 1] == 'H')
            w[++ cnt] = 1;
    }
    
    int res = 0;
    for(int i = 1; i <= cnt; ++ i)
        if(w[i] ^ w[i + 1])
            res ++;
            
    cout << res;
    
    return 0;
}