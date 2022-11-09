//https://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n = 0;
    string OP;
    cin >> n >> OP;
    
    int cur = 1, f, r;//当前光标， 界面最上， 界面最下
    f = 1;//初始化界面头尾
    r = n < 4 ? n : 4;
    
    for(auto& op : OP)
    {
        if(op == 'U')//向上走
        {
            if(cur == 1)//如果为第第一首，需要特殊翻页
            {
                cur = n;
                r = n;
                f = n < 4 ? 1 : n - 3;//若<=4， 不翻页
            }
            else
            {
                
                if(cur == f)//判断是否需要普通翻页
                {
                    -- f;
                    -- r;
                }
                -- cur;
            }
        }
        else if(op == 'D')
        {
            if(cur == n)//最后一首， 特殊翻页
            {
                cur = 1;
                f = 1;
                r = n < 4 ? n : 4;
            }
            else
            {
                if(cur == r)
                {
                    ++ f;
                    ++ r;
                }
                ++ cur;
            }
        }
    }
    
    while(f <= r)
    {
        cout << f << ' ';
        ++ f;
    }
    cout << endl << cur;
    
    return 0;
}