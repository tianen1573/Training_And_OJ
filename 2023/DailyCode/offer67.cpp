class Solution {
public:
    int strToInt(string str) {
        
        int f = 1;
        long long val = 0;
        int pos = 0;

        while(pos < str.size() && str[pos] == ' ') ++ pos;
        if(str[pos] == '+') f = 1, ++ pos;
        else if(str[pos] == '-') f = -1, ++ pos;
       
       if(f == 1)
       {
           while(pos < str.size() && isdigit(str[pos]))
           {
               long long num = val * 10 + (str[pos] - '0');
               if(num > (long long)INT_MAX)
               {
                   val = INT_MAX;
                   break;
               }
               else
               {
                   val = (int)num;
                   ++ pos;
               }
           }
       }
       else
       {
           while(pos < str.size() && isdigit(str[pos]))
           {
               long long num = val * 10 - (str[pos] - '0');
               cout << str[pos];
               if(num < (long long)INT_MIN)
               {
                   val = INT_MIN;
                   break;
               }
               else
               {
                   val = (int)num;
                   pos ++;
               }
           }
       }
        return val;
    }
};