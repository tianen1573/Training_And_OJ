
/*�����Ĵ�����һ�������ͷ�����һ�����ַ�����
����"level"���ߡ�noon"�ȵȾ��ǻ��Ĵ���
�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
�������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ���
����ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ���
����ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��*/

#include<iostream>
#include<string>
using namespace std;

bool IsPalindrome(string& str)
{
    for(int i = 0, j = str.size() - 1; i < j; ++i, --j)
    {
        if(str[i] != str[j])
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    string strA, strB;
    cin >> strA >> strB;
    
    int cnt = 0;
    for(int i = 0; i <= strA.size(); ++i)
    {
        string tmp = strA.substr(0, i) + strB + strA.substr(0 + i, string::npos);
        if(IsPalindrome(tmp))
        {
            ++cnt;
        }
    }
    
    cout << cnt;
    
    return 0;
}