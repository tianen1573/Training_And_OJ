#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/weekly-contest-300/ */


/* 解密信息 */
//class Solution {
//
//public:
//    string decodeMessage(string key, string message) {
//
//        bool sta[26] = { 0 };
//        char k[26];
//        int pos = 0;
//        for (auto x : key)
//        {
//            if (x == ' ' || sta[x - 'a']) continue;
//            k[x - 'a'] = 'a' + pos;
//            sta[x - 'a'] = true;
//            pos++;
//        }
//
//        for (auto& x : message)
//            if (x != ' ') x = k[x - 'a'];
//
//        return message;
//
//    }
//};


/*螺旋矩阵Ⅳ*/
// /**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
//        cin >> m >> n;
//        vector<vector<int>> map(m, vector<int>(n));
//        int dir[4][2] = { {0,1},{1,0},{0,-1},{-1, 0} };
//
//        for (int i = 0; i < m; i++)
//            for (int j = 0; j < n; j++) map[i][j] = -1;
//
//        int row = 0, col = 0, D = 0;
//        while (head)
//        {
//            map[row][col] = head->val;
//            //找下一个位置
//            bool lag = true;
//            while (lag)
//            {
//                int rr = row + dir[D][0], cc = col + dir[D][1];
//                if (rr < 0 || rr >= m || cc < 0 || cc >= n || map[rr][cc] > -1)//越界或已访问
//                {
//                    D = (D + 1) % 4;
//                }
//                else
//                {
//                    row = rr;
//                    col = cc;
//                    lag = false;//跳出找位置
//                }
//            }
//
//            head = head->next;
//        }
//        return map;
//    }
//};

/*知道密码的人数*/
//class Solution {
//    const int MOD = 1e9 + 7;
//public:
//    int peopleAwareOfSecret(int n, int delay, int forget) {
//        int cnt = 0;
//        int dp[n]; memset(dp, 0, sizeof(dp));
//        dp[0] = 1;
//        for (int i = 0; i < n; ++i)
//            for (int j = i + delay; j < min(i + forget, n); ++j)
//                dp[j] = (dp[j] + dp[i]) % MOD;
//        for (int i = n - forget; i < n; i++)
//            cnt = (cnt + dp[i]) % MOD;
//        return cnt;
//    }
//};
////dp[i]表示第i天新增知道秘密的人数，则通过第i天，可以知道[i+del, i+forget-1]期间每天新增dp[i]个人
////记录在第n天仍记得密码的人数， 即[(n - 1)-forget+1, (n - 1)]期间的人数即可。