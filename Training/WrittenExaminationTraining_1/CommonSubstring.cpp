// ���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
// ע:�Ӵ��Ķ���:��һ���ַ���ɾȥǰ׺�ͺ�׺��Ҳ���Բ�ɾ���γɵ��ַ�������͡�������"�ĸ���ֿ�!
// ���ݷ�Χ:�ַ�������1 ��length ��300
// ����:ʱ�临�Ӷ�:O(n3)���ռ临�Ӷ�:��(n)
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    
    if(b.size() > a.size())
    {
        swap(a, b);
    }
    
    //�����Ӵ���󳤶�Ϊ�϶̵��ַ����ĳ���
    //�ӳ����̣��������ң����α���
    for(int len = b.size(); len >= 1; --len)//������
    {
        for(int pos_b = 0; pos_b + len - 1 < b.size(); ++pos_b)//������
        {
            string tmp = b.substr(pos_b, len);//��¼�ַ���
            int pos = a.find(tmp);
            if(pos != string::npos)//����
            {
                cout << tmp;
	      //cout << len;//�������
                return 0;
            }
        }
    }
    
    cout << "";
    //cout << 0;
    return 0;
}