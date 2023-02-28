
/* 思路：W和B的奇偶，一方为0
* 将砖块转换成一样的颜色，代表有一方其数量为0
* 根据模拟，只有BB->WW，WW->BB，才会发生数量变化，即一方+2，一方-2
* 那么必须要求至少一方其数量为偶数，否则无解
* 决定翻转的颜色为偶数个的颜色，根据上面的结论：假设翻转B
* 那么BB会翻转为WW，BW会翻转成WB，则这个翻转后的B在向另一个B靠拢
* 极端为两头各有一个B，最多翻转n次，满足条件
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int T, n;
    string str;
    cin >> T;
    
    while(T--)
    {
        cin >> n >> str;
        int cnt_B = 0, cnt_W = 0;
        for(auto ch : str)
            if('B' == ch) cnt_B++;
            else cnt_W++;
            
        if(0 == cnt_W * cnt_B)//同颜色
        {
            cout << "0" << endl;
        }
        else if(cnt_B % 2 && cnt_W % 2)//都是奇数个
        {
            cout << "-1" << endl;
        }
        else
        {
            char flag = (cnt_B % 2 ? 'W' : 'B'); //cout << flag;
            char change = 'W' ^ 'B'; //cout << (char)('B' ^ change);
            vector<int> print;
            
            for(int i = 0; i < str.size(); ++ i)
            {
                if(flag == str[i])
                {
                    print.push_back(i + 1);
                    str[i + 1] ^= change;
                }
            }
            
            cout << print.size() << endl;
            for(auto num : print)
                cout << num << ' ';
            cout << endl;
        }
    }
    
    return 0;
}