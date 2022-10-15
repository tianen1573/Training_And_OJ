
// ��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯����
// ��ֵΪ�������ַ�������һ���Ϸ�����ֵ�򷵻�0
// ���ݷ�Χ:�ַ�����������0<n ��100
// ����:�ռ临�Ӷ�O(1)��ʱ�临�Ӷ�O(n)


class Solution {
public: 
    int StrToInt(string str) {
        
        if(str == "" || str == "0")
        {
            return 0;
        }
        
        int res = 0;
        int flag = 1;
        int i = 0;
        
        if(str[0] == '-' || str[0] == '+')
        {
            flag = str[0] == '-' ? -1 : 1;
            ++i;
        }
        
        while(i < str.size())
        {
            if(str[i] < '0' || str[i] > '9')
            {
                return 0;
            }
            res = res * 10 + str[i] - '0';
            ++i;
        }
        
        res *= flag;
        
        return res;
        
    }
};