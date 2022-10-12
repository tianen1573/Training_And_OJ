/*Ħ��������*/


class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * 
     * @param numbers int����vector 
     * @return int����
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        
        int res = numbers[0];
        int count = 1;
        
        for(auto& val : numbers)
        {
            if(val == res)
            {
                ++count;
            }
            else if(--count == 0)
            {
                res = val;
                count = 1;
            }
        }
        
        return res;
        
    }
};