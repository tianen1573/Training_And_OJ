
/* ˼·��W��B����ż��һ��Ϊ0
* ��ש��ת����һ������ɫ��������һ��������Ϊ0
* ����ģ�⣬ֻ��BB->WW��WW->BB���Żᷢ�������仯����һ��+2��һ��-2
* ��ô����Ҫ������һ��������Ϊż���������޽�
* ������ת����ɫΪż��������ɫ����������Ľ��ۣ����跭תB
* ��ôBB�ᷭתΪWW��BW�ᷭת��WB���������ת���B������һ��B��£
* ����Ϊ��ͷ����һ��B����෭תn�Σ���������
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int T, n;
    string str;
    cin >> T;
    
    while(T--)
    {
        cin >> n >> str;
        int cnt_B = 0, cnt_W = 0;
        for(auto ch : str)
            if('B' == ch) cnt_B++;
            else cnt_W++;
            
        if(0 == cnt_W * cnt_B)//ͬ��ɫ
        {
            cout << "0" << endl;
        }
        else if(cnt_B % 2 && cnt_W % 2)//����������
        {
            cout << "-1" << endl;
        }
        else
        {
            char flag = (cnt_B % 2 ? 'W' : 'B'); //cout << flag;
            char change = 'W' ^ 'B'; //cout << (char)('B' ^ change);
            vector<int> print;
            
            for(int i = 0; i < str.size(); ++ i)
            {
                if(flag == str[i])
                {
                    print.push_back(i + 1);
                    str[i + 1] ^= change;
                }
            }
            
            cout << print.size() << endl;
            for(auto num : print)
                cout << num << ' ';
            cout << endl;
        }
    }
    
    return 0;
}