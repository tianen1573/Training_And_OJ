// д��һ�����򣬽���һ������ĸ�����ֺͿո���ɵ��ַ�������һ���ַ���Ȼ����������ַ����и��ַ��ĳ��ִ�����(�����ִ�Сд��ĸ)
// ���ݷ�Χ:1<n <1000
// ��������:
// ��һ������һ������ĸ�������Լ��ո���ɵ��ַ������ڶ�������һ���ַ���
// �������:
// ��������ַ����к��и��ַ��ĸ�����(�����ִ�Сд��ĸ)

#include<iostream>
#include<map>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    char ch;
    cin >> ch;
    
    map<char, int> mvc;
    
    for(auto& x : str)
    {
        if(x >= 'A' && x <= 'Z')
        {
            x = x + 32;
        }
        mvc[x]++;
    }
    if(ch >= 'A' && ch <= 'Z')
    {
        ch = 'A' + 32;
    }
    cout << mvc[ch];
    
    return 0;
}