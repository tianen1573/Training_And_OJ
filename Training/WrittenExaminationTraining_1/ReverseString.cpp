// ·´×ª×Ö·û´®
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;
    
//     reverse(str.begin(), str.end());
    
    int begin = 0, end = str.size() - 1;
    
    while(begin < end)
    {
        swap(str[begin++], str[end--]);
    }
    
    cout << str;
    
    return 0;
}