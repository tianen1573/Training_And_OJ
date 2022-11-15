// Êý¸ù
// https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
#include<iostream>
#include<string>
using namespace std;

int getN(string num)
{
    int res = 0;
    
    for(auto ch : num)
    {
        res += (ch - '0');
    }
    
    if(res < 10)
        return res;
    else
        return getN(to_string(res));
}

int main()
{
    string num;
    
    while(cin >> num)
    {
        int res = getN(num);
        cout << res << endl;
    }
    
    return 0;
}