class Solution {
public:
    int nthUglyNumber(int n) {

        vector<long long> dp(n);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for(int i = 1; i < n; ++ i)
        {
            long long n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5);

            //每个都要判断
            if(dp[i] == n2) ++ a;
            if(dp[i] == n3) ++ b;
            if(dp[i] == n5) ++ c;
        }

        return dp[n - 1];

    }
};

// class Solution {
// public:

//     typedef long long LL;

//     int nthUglyNumber(int n) {

//         priQue.push(1);
//         unSet.insert(1);
//         while(n --)
//         {
//             LL cur = priQue.top();
//             priQue.pop();

//             if(n == 0) return cur;

//             LL v1 = cur * 2;
//             LL v2 = cur * 3;
//             LL v3 = cur * 5;

//             if(unSet.find(v1) == unSet.end()) unSet.insert(v1), priQue.push(v1);
//             if(unSet.find(v2) == unSet.end()) unSet.insert(v2), priQue.push(v2);
//             if(unSet.find(v3) == unSet.end()) unSet.insert(v3), priQue.push(v3);
//         }
        
//         return -1;
//     }

// priority_queue<LL, vector<LL>, greater<LL>> priQue;
// unordered_set<LL> unSet;
// };