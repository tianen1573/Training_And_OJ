//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
#include<iostream>
#include<map>
#include<string>

using namespace std;


int main()
{
    string str;
    map<char, int> mcc;
    
    cin >> str;
    
    for(auto& ch : str)
    {
        mcc[ch]++;
    }
    
    for(auto& ch : str)
    {
        if(mcc[ch] == 1)
        {
            cout << ch;
            return 0;
        }
    }
    
    cout << "-1";
    return 0;
}