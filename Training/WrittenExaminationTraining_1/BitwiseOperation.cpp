
// ��������32λ����n��m��ͬʱ����i��j��
// ��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ,��֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i-j+1��
// ���ж����Ƶ�λ����0��ʼ�ɵ͵��ߡ�


class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        int res = n;
        
        for(int k = 0, p = j; k < i - j + 1; ++k, ++p)
        {
            //m����kλ������1���õ�kλ����ֵ�� 
            //����pλ����Ӧres�����λ��
            res |= (m >> k & 1) << p;
        }
        
        return res;
    }
};