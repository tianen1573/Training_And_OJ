
/*
* ���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
* ���磬����"They are students."��"aeiou����
* ��ɾ��֮��ĵ�һ���ַ������"Thy r stdnts."
*/

/*
����hash�洢���ٲ���
*/

#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main()
{
    string s1, s2, res;
    unordered_set<char> hash;
    
    getline(cin, s1);
    getline(cin, s2);
    
    for(auto& x : s2)
    {
        hash.insert(x);
    }
    
    for(auto& x : s1)
    {
        if(hash.find(x) == hash.end())
        {
            res += x;
        }
    }
    
    cout << res;
    
    return 0;
}