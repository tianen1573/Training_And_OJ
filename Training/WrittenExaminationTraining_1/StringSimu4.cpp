
/*按要求提取字符串内容，模拟*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main()
{
    string str;
    getline(cin, str);
    
    vector<string> res;
    string cur;
    
    for(int i = 0; i < str.size(); ++i )
    {
        if(str[i] == ' ')
        {
            res.push_back(cur);
            cur = "";
        }
        
        else if(str[i] == '"')
        {
            ++i;
            while(str[i] != '"')
            {
                cur += str[i];
                ++i;
            }
        }
        
        else
        {
            cur += str[i];
        }
    }
    if(cur != "")
    {
        res.push_back(cur);
    }
    
    cout << res.size() << endl;
    
    for(auto& s : res)
    {
        cout << s << endl;
    }
    
    return 0;
}