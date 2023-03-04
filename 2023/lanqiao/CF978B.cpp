#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;
    
    int x_cnt = 0, op = 0;
    
    for(auto& ch : str)
    {
        if('x' == ch)
            x_cnt++;
        else
            x_cnt = 0;
            
        if(3 == x_cnt)
        {
            x_cnt --;
            op ++;
        }
    }
    
    cout << op;
    
    return 0;
}