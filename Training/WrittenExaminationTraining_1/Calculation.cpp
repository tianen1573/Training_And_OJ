
/*
A,B,C�������Ǻ�����,ÿ�������ﶼ��һЩ�ǹ�,���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�,��������֪�����µ���Ϣ:
A-B,B - C,A+B,B��C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�,��A,B,C�����ﱣ֤���ֻ��һ������A,B,C������������������
���������No
*/

#include<iostream>
using namespace std;

int main()
{
    int a_b, b_c, ab, bc;
    cin >> a_b >> b_c >> ab >> bc;
    
    int a, b, c;
    
    a = (a_b + ab) / 2;
    b = (b_c + bc) / 2;
    c = (bc - b_c) / 2;
    
    //�ж��Ƿ����
    if(a >= 0 && b >= 0 && c >= 0 
       && a * 2 == a_b + ab && b * 2 == b_c + bc && c * 2 == bc - b_c)
    {
        cout << a << ' ' << b << ' ' << c;
    }
    else
    {
        cout << "No";    
    }
    
    
    return 0;
}