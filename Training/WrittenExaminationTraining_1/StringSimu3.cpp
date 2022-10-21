
//��ģ�⣬������
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
    string pwd;
    cin >> pwd;
    
    int res = 0;//�ܷ�
    set<char> cnt_num, cnt_symbol;//��Ӧ�ַ�����
    bool sta_num = false, sta_char = false, sta_symbol = false, sta_UP = false;//��Ӧ����״̬
    
    for(auto& x : pwd)
    {
        if(isalpha(x))//��ĸ
        {
            if(islower(x))//Сд
            {
                sta_char = true;
            }
            else//��д
            {
                sta_UP = true;
            }
                   
        }
        else if(isdigit(x))//����
        {
            sta_num = true;
            cnt_num.insert(x);
        }
        else//����
        {
            sta_symbol = true;
            cnt_symbol.insert(x);
        }
    }
    
    //����
    if(pwd.size() <= 4)
    {
        res += 5;
    }
    else if(pwd.size() <= 7)
    {
        res += 10;
    }
    else
    {
        res += 25;
    }
    //��ĸ
    if(sta_char || sta_UP)
    {
        if(sta_char && sta_UP)
        {
            res += 20;
        }
        else
        {
            res += 10;
        }
    }
    //����
    if(sta_num)
    {
        if(cnt_num.size() == 1)
        {
            res += 10;
        }
        else
        {
            res += 20;
        }
    }
    //����
    if(sta_symbol)
    {
        if(cnt_symbol.size() == 1)
        {
            res += 10;
        }
        else
        {
            res += 25;
        }
    }
    //����
    if(sta_char && sta_UP && sta_num && sta_symbol)
    {
        res += 5;
    }
    else if((sta_char || sta_UP) && sta_num && sta_symbol)
    {
        res += 3;
    }
    else if((sta_char || sta_UP) && sta_num)
    {
        res += 2;
    }

    //����
    if(res >= 90)
    {
        cout << "VERY_SECURE";
    }
    else if(res >= 80)
    {
        cout << "SECURE";
    }
    else if(res >= 70)
    {
        cout << "VERY_STRONG";
    }
    else if(res >= 60)
    {
        cout << "STRONG";
    }
    else if(res >= 50)
    {
        cout << "AVERAGE";
    }
    else if(res >= 25)
    {
        cout << "WEAK";
    }
    else if(res >= 0)
    {
        cout << "VERY_WEAK";
    }
    
    
}