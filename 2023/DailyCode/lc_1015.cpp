class Solution {
public:
    //只想到了第一种
    //by 灵神
    int smallestRepunitDivByK(int k) {
        
        ////思路1
        // unordered_set<int> uq;

        // //同余定理： (x + y) % k == (x%k + y%k)%k; (x * y) % k = ((x%k) * (y%k)) % k;
        // //又：y = x * 10 + 1; 可得
        // //y % k == (x * 10 + 1) % k == (((x % k) * (10 % k ->> 10[暂时不模])) % k + (1 % k ->> 1 [暂时不模]))
        // //-》》 (x * 10 + 1) % k;
        // int x = 1 % k;//x作为余数

        // while(x && !uq.count(x))
        // {
        //     uq.insert(x);
        //     x = (x * 10 + 1) % k;
        // }

        // return x ? -1 : uq.size() + 1;


        ////思路2
        //必定有解
        if(k % 2 == 0 || k % 5 == 0) return -1;

        int x = 1 % k;

        for(int i = 1; ; ++ i)
        {
            if(x == 0)
                return i;
            x = (x * 10 + 1) % k;
        }

    }
};