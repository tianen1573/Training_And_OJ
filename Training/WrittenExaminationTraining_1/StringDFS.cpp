// ��������:�ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢i������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
// Ҫ��:
// ʵ������2��ͨ���:
// *:����O�������ϵ��ַ�(ע:�ܱ�*��?ƥ����ַ�����Ӣ����ĸ������0��9��ɣ���ͬ)
// ?��ƥ��1���ַ�
// ע��:ƥ��ʱ�����ִ�Сд��
#include <iostream>
#include <string>
using namespace std;
// https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036
bool match(const char* pattern, const char *str)
{
    if (*pattern == '\0' && *str == '\0')    //��ǰ�ַ�����������true
    {
        return true;
    }
    if (*pattern == '\0' || *str == '\0')    //�����ַ�����һ���Ƚ������򷵻�false
    {
        return false;
    }
    
    if (*pattern == '?')   //����?�ţ�ƥ��һ���ַ���������һ��λ��
    {  
        if(!isalnum(*str)) //��ƥ����ĸ������
        {
            return false;
        }
        return match(pattern + 1, str + 1);
    }
    else if (*pattern == '*')
    {
        //�ϲ�*
        int cnt = 1;
        while(*(pattern + cnt) == '*')
        {
            cnt++;
        }
        --cnt;
        // ����*�ţ�ƥ��0��(str��Ų��)��1�������߶���ǰŲ��һ���ַ�������(str��ǰŲ��һ���ַ�)
        return match(pattern + cnt + 1, str) 
            || match(pattern + cnt + 1, str + 1) 
            || match(pattern, str + 1);
    }
    else if (*pattern == *str)//�����ǰ�ַ���ȣ�ƥ����һ���ַ�
    {    
        return match(pattern + 1, str + 1);
    }
    return false;
}
int main(){
    string pattern, str;    //pattern��ʽ�ַ�����strʵ���ַ���
    while (cin >> pattern >> str){
        //ת����Сд
        for(auto& x : pattern)
        {
            if(x >= 'A' && x <= 'Z')
            {
                x += 32;
            }
        }
        for(auto& x : str)
        {
            if(x >= 'A' && x <= 'Z')
            {
                x += 32;
            }
        }
        
        bool ret = match(pattern.c_str(), str.c_str());
        if (ret)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}