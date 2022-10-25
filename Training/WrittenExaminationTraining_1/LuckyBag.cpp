
// һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)��
// ���һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
// ����:��������������ĺ�����{1,1,2,3}��������Ӿ������˵ģ���Ϊ1+1+2+3>1*1* 2* 3
// ������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��,���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ�
// ���������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�


/* https://www.nowcoder.com/questionTerminal/a5190a7c3ec045ce9273beebdfe029ee */

// a + b > a * b, ������һ��Ϊ1�� �Ҳ���ͬʱΪ1
// �� sum <= pro, �� ��������ֻ��Ϊ1�� ���п��� ���� sumNew > proNew
// �����Ȱ� ���е�1 ���������Ϊ��ײ㣬 ��ʣ�µ���ȫ�Ǵ���1��
// ��ô sumNew < proNew ʱ�� ��ֱ�ӽ������������� ��Ϊ�������µ�1������ʹ�����ϱ������

#include<iostream>
#include<map>
using namespace std;

#define x first
#define y second

typedef long long LL;
typedef pair<int, long long > pil;

map<int, int> mvc;
map<pil, int> spc, tmpM;

int main()
{
    int n = 0;
    cin >> n;
    
    //ͳ�ƺ���ĸ���
    for(int i = 0; i < n; ++ i)
    {
        int tmp = 0;
        cin >> tmp;
        mvc[tmp]++;
    }
    
    //������1ֱ�����
    if(mvc[1] == 0)
    {
        cout << "0";
        return 0;
    }
    //�Ƚ�1��Ϊ�ײ㣬 Ϊ������������Ҫ�������׼��
    pil tmp = {1, 1};//{1��1}������
    spc[tmp] += 1;
    long long res = 0;
    for(int i = 2; i <= mvc[1]; ++ i)
    {
        tmp.x += 1;
        tmp.y *= 1;
        
        ++res;//����1��1�� �������˵�

        spc[tmp] += 1;
    }
    mvc.erase(1);
    
    for(auto num : mvc)//��� ���� �� ����
    {  
        //��֮ǰ�����
        tmpM = spc;//��ǰ�仯���ܻ�Ӱ�����Ĳ����� ����һ��
        for(auto& val : tmpM)//���� �� �ͻ� �� ����
        {
            tmp = val.x;
            for(int i = 1; i <= num.y; ++ i)
            {
                tmp.x += num.x;
                tmp.y *= num.x;

                if(tmp.x > tmp.y)
                {
                    res += val.y;
                    spc[tmp] += val.y;
                }
                else//�����ں���1�� �� �޷�ʹ��������� �� ����
                {
                    break;
                }
    
            }
        }
    }
    
    cout << res;
    return 0;
}