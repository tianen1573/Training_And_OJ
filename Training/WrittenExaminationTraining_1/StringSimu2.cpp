
// ��������:
// �����һ��Ϊ�ַ�������n (n �� 100)
// ��������n��,ÿ��һ���ַ���,�ַ������Ⱦ�С��100������Сд��ĸ���
// �������:
// �����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically"��
// ������ݳ������ж������ֵ����������"lengths" ,
// ������ַ�ʽ���������"both"���������"none"

#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    
    bool isLen = true, isDir = true;
    string a, b;
    
    
    --n;
    cin >> a;
    
    while(n > 0)
    {
        cin >> b;
        if( b.size() < a.size())
        {
            isLen = false;
        }
        if(b < a)
        {
            isDir = false;
        }
        
        a = b;
        --n;
    }
    
    if(isLen && isDir)
    {
        cout << "both";
    }
    else if(isLen && !isDir)
    {
        cout << "lengths";
    }
    else if(!isLen && isDir)
    {
        cout << "lexicographically";
    }
    else
    {
        cout << "none";   
    }
    
    return 0;
}

��С������
#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if(a < b)
    {
        return gcd(b, a);
    }
    else if(a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);   
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    
    cout << a * b / gcd(a, b);
    
    return 0;
}