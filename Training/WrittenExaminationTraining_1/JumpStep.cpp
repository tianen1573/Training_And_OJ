// ��̨����չ����
// https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
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