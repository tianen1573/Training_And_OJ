// write your code here cpp

#include<iostream>

using namespace std;

int main()
{
    string str, sub;
    while(cin >> str >> sub)
    {
        int p = 0, cnt = 0;
        int L = sub.size();

        while(p < str.size())
        {
            p = str.find(sub, p);
            if(p == string::npos) break;
            p += L;
            cnt ++ ;
        }
    
        cout << cnt << endl;
    }
    
    
    
    return 0;
}