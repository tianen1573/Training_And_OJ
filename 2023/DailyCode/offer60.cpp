class Solution {
public:
    vector<double> dicesProbability(int n) {

        vector<double> vec = {0, 1.0/6.0,1.0/6.0,1.0/6.0,1.0/6.0,1.0/6.0,1.0/6.0};

        int Max = 6;//能投出来的最大点数
        int Min = 1;//最小点数
        for(int i = 2; i <= n; ++ i)
        {
            vector<double> tmp(Max + 1 + 6, 0);

            for(int k = Min; k <= Max; ++ k)
                for(int j = 1; j <= 6; ++ j)
                    tmp[j + k] += vec[k] * 1.0 / 6.0;
                
            Min += 1;
            Max += 6;
            swap(vec, tmp);
        }

        vec.erase(vec.begin(), vec.begin() + Min);

        return vec;

    }
};