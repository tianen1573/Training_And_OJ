//https://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n = 0;
    string OP;
    cin >> n >> OP;
    
    int cur = 1, f, r;//��ǰ��꣬ �������ϣ� ��������
    f = 1;//��ʼ������ͷβ
    r = n < 4 ? n : 4;
    
    for(auto& op : OP)
    {
        if(op == 'U')//������
        {
            if(cur == 1)//���Ϊ�ڵ�һ�ף���Ҫ���ⷭҳ
            {
                cur = n;
                r = n;
                f = n < 4 ? 1 : n - 3;//��<=4�� ����ҳ
            }
            else
            {
                
                if(cur == f)//�ж��Ƿ���Ҫ��ͨ��ҳ
                {
                    -- f;
                    -- r;
                }
                -- cur;
            }
        }
        else if(op == 'D')
        {
            if(cur == n)//���һ�ף� ���ⷭҳ
            {
                cur = 1;
                f = 1;
                r = n < 4 ? n : 4;
            }
            else
            {
                if(cur == r)
                {
                    ++ f;
                    ++ r;
                }
                ++ cur;
            }
        }
    }
    
    while(f <= r)
    {
        cout << f << ' ';
        ++ f;
    }
    cout << endl << cur;
    
    return 0;
}