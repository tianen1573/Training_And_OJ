//https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b
#include<iostream>
#include<string>
using namespace std;

char arr[] = "VWXYZABCDEFGHIJKLMNOPQRSTU";

int main()
{
    string str;
    while(getline(cin, str))
    {
        string res;
        for(auto& x : str)
        {
            if(!isupper(x))
                res += x;
            else
                res += arr[x - 'A'];
        }
        
        cout << res << endl;
    }
    
    return 0;
}