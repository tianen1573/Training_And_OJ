// �쵽������
// https://www.nowcoder.com/questionTerminal/82424d93369649b98720743c25edc6ce

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * 
     * @param number int���� 
     * @return int����
     */
    int jumpFloorII(int number) {
           
        int res = (int)pow(2, number - 1);
        
        return res;
      
    }
};