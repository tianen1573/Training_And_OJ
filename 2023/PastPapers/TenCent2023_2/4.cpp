
// 对于一个字符串，如果把字符串的第一个字符放到最后，得到的新串就是原来字符串的旋转串。
// 一个字符串的旋转串的旋转串也是这个字符串的旋转串。即这种关系具有传递性。
// 例如abc的旋转串有: bca cab abc
// 如果存在一个字符串，既是x的旋转串也是y的旋转串，那么我们称x,y 匹配。请回答—系列字符串中是否有两个字符串匹配。


// 思路：只将字典序最小的旋转串放入字典树中

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void insert(vector<vector<int>>& tire, vector<bool>& st, string& str)
{
    int p= 0, idx = 0;
    for(int i = 0; i < str.size(); ++ i)
    {
        int& son = tire[p][str[i] - 'a'];
        if(son == 0)
        {
            son = tire.size();
            tire.emplace_back(vector<int>(26, 0));
            st.push_back(false);
        }
        
        p = son;
    }
    st[p] = true;
}
bool search(vector<vector<int>>& tire, vector<bool>& st, string& str)
{
    int p = 0;
    for(int i = 0; i < str.size(); ++ i)
    {
        if(!tire[p][str[i] - 'a'])
            return false;
        p = tire[p][str[i] - 'a'];
    }
    
    return st[p];
}
void reverse(string& str, int l, int r)
{
    while(l < r)
    {
        swap(str[l], str[r]);
        ++ l, -- r;
    }
}

int main()
{
   
    int t;
    cin >> t;
    while(t --)
    {
        vector<vector<int>> tire;
        vector<bool> st;
        tire.emplace_back(vector<int>(26, 0));
        st.push_back(false);
        
        int n = 0; cin >> n;
        vector<string> arr;
        for(int i = 0; i < n; ++ i)
        {
            string tmp;
            cin >> tmp;
            arr.emplace_back(tmp);
        }
        
        bool flag = true;
        for(auto & str : arr)
        {
            if(search(tire, st, str))
            {
                cout << "YES" << endl;
                flag = false;
                break;
            }
            else
            {
                for(int i = 0; i < str.size(); ++ i)
                {
                    string tmp = str;
                    reverse(str, 0, i - 1);
                    reverse(str, i, str.size() - 1);
                    reverse(str, 0, str.size() - 1);
                    insert(tire, st, str);
                }
            }
        }
        
        if(flag)
            cout << "NO" << endl;
    }
    
    return 0;
}