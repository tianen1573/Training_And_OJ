// https://www.nowcoder.com/questionTerminal/d290db02bacc4c40965ac31d16b1c3eb
// �˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ(���У�Сдjoker��ʾС������дJOKER��ʾ����)��
// 345678910JQKA2 joker JOKER
// ���������ƣ�������֮����"��"���ӣ�ÿ���Ƶ�ÿ�����Կո�ָ���""����û�пո���:444 4-joker JOKER��
// ��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR��
// ��������:
// (1)����ÿ���ƿ����Ǹ��ӡ����ӡ�˳��(����5��)��������ը��(�ĸ�)�Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С��������;
// (2)����ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ(�磬���Ӹ����ӱȽϣ������������Ƚ�)�������ǲ������(��:�����Ӳ�ֳɸ���) ;
// (3����С��������ƽʱ�˽�ĳ���������ͬ�����ӡ����ӡ������Ƚ������С;˳�ӱȽ���С�ƴ�С;ը������ǰ�����е��ƣ�ը��֮��Ƚ������С;������������;
// (4������������Ʋ��������ȵ���������ݷ�Χ:�ַ�������:3<s�� 10


#include<iostream>
#include<string>
using namespace std;


// �����Ӧ���ַ���������ʵ���ֵ��� ��һЩ�ַ��滻��ԭ�����ƣ� ʹ�������ֵ���
// ���߶���һ����ֵ�ԣ����¸�Ȩ��
int main()
{
    string str;
    getline(cin, str);
    
    //��ȡ����
    int pos = str.find('-');
    string strL = str.substr(0, pos), strR = str.substr(pos + 1);
    
    //�Ƚϴ�С
    string left, right;
    bool l = true;
    
    for(int i = 0; i < str.size(); ++ i)
    {
        if(str[i] == ' ')//�ո�
        {
            continue;
        }
        if(str[i] == '-')//�ڶ�������
        {
            l = false;
            continue;
        }
        
        //ת���ַ��� ʹ���ֵ��������һ��
        if(str[i] == '1')//�� 10 ת�� �� @
        {
            ++i;
            str[i] = '@';
        }
        else if(str[i] == 'A')//�� A ת�� a
        {
            str[i] = 'a';
        }
        else if(str[i] == '2')//�� 2 ת�� b
        {
            str[i] = 'b';
        }
        else if(str[i] == 'Q')//�� Q ת�� K
        {
            str[i] = 'K';
        }
        else if(str[i] == 'K')//�� K ת�� Q
        {
            str[i] = 'Q';
        }
        
        if(l)
        {
            left += str[i];
        }
        else
        {
            right += str[i];
        }
    }
    
    if(left.size() == 1)//����
    {
        if(right.size() == 1)//����
        {
            cout << (right > left ? strR: strL);
        }
        // ը���� ������ ����
        else if(right.size() == 4 || right.size() == 10 || right == "joker" || right == "JOQER")
        {
            cout << strR;
        }
        else
        {
            cout << "ERROR";
        }
    }
    else if(left.size() == 2)//����
    {
        if(right.size() == 2)//����
        {
            cout << (right > left ? strR: strL);
        }
        // ը���� ����
        else if(right.size() == 4 || right.size() == 10)
        {
            cout << strR;
        }
        else
        {
            cout << "ERROR";
        }
    }
    else if(left.size() == 3)//����
    {
        if(right.size() == 3)//����
        {
            cout << (right > left ? strR: strL);
        }
        // ը���� ����
        else if(right.size() == 4 || right.size() == 10)
        {
            cout << strR;
        }
        else
        {
            cout << "ERROR";
        }
    }
    else if(left.size() == 4)//ը��
    {
        if(right.size() == 4)//ը��
        {
            cout << (right > left ? strR: strL);
        }
        // ����
        else if(right.size() == 10)
        {
            cout << strR;
        }
        else
        {
            cout << strL;
        }
    }
    else if(left.size() == 5 && left != "joker" && left != "JOQER")//˳��
    {
        if(right.size() == 5 && right != "joker" && right != "JOQER")//˳��
        {
            cout << (right > left ? strR: strL);
        }
        // ը���� ����
        else if(right.size() == 4 || right.size() == 10)
        {
            cout << strR;
        }
        else
        {
            cout << "ERROR";
        }
    }
    else if(left == "joker" || left == "JOQER")
    {
        if(left == "joker")
        {
            if(right.size() == 1)
            {
                cout << strL;
            }
            else if(right == "JOQER")
            {
                cout << strR;
            }
            else if(right.size() == 4 || right.size() == 10)
            {
                cout << strR;
            }
            else
            {
                cout << "ERROR";
            }
        }
        else if(left == "JOQER")
        {
            if(right.size() == 1)
            {
                cout << strL;
            }
            else if(right == "joker")
            {
                cout << strL;
            }
            else if(right.size() == 4 || right.size() == 10)
            {
                cout << strR;
            }
            else
            {
                cout << "ERROR";
            }
        }
    }
    else if(left.size() == 10)
    {
        cout << strL;
    }
    
    
    return 0;
}