#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param t string字符串 
     * @return int整型
     */
    unordered_set<string> hash{"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    int binSearch(int star, int l, int r, string& str)
    {
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(hash.count(str.substr(star, mid - star + 1)))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
    int cntOfMethod(string t) {
        
        vector<long long> sub(t.size() + 1, 0);
        unordered_set<string> preStr{""};

        const int MOD = 1e9 + 7;
        long long sum = 1;
        long long ans = 0;
        for(int i = 0; i < t.size(); ++ i)
        {
            int end = binSearch(i, i, t.size() - 1, t);
            string son = t.substr(i, end - 1);
            ++ sub[i], -- sub[end + 1];

            if(end = t.size() - 1)
            {
                ans += sum;
                ans %= MOD;
            }
            sum += sub[i];
            sum %= MOD;

            unordered_set<string> tmp{""};
            for(auto str : preStr)
            {
                hash.emplace(str + t[i]);
                tmp.emplace(str + t[i]);
            }
            preStr = tmp;
        }

        

        


        return ans;
    }
};