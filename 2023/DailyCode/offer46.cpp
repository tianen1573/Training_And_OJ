class Solution {
public:
    int translateNum(int num) {

        string str = to_string(num);

        int a = 1, b = 1, c = 1;
        for(int i = 1; i < str.size(); ++ i)
        {
            c = 0;

            if(str[i - 1] == '0')
            {
                c = b;
                a = b;
                continue;
            }
            c = b;
            if((str[i - 1] - '0') * 10  + str[i] - '0' <= 25)
            {
                c += a;
            }
            a = b;
            b = c;
               
        }

        return c;

    }
};