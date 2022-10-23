
// 给定两个32位整数n和m，同时给定i和j，
// 将m的二进制数位插入到n的二进制的第j到第i位,保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1，
// 其中二进制的位数从0开始由低到高。


class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        int res = n;
        
        for(int k = 0, p = j; k < i - j + 1; ++k, ++p)
        {
            //m右移k位后与上1，得到k位的数值， 
            //左移p位，对应res插入的位置
            res |= (m >> k & 1) << p;
        }
        
        return res;
    }
};