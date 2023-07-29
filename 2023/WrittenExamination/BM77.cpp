// class Solution {
// public:
    
//     // 滑动窗口
//     int longestValidParentheses(string s) {
        
//         queue<char> que;
//         int maxLen = 0;
//         int diff = 0;
//         for(auto ch : s)
//         {
//             que.push(ch);
//             if(ch == '(') ++ diff;
//             else -- diff;

//             if(diff < 0)
//             {
//                 que = queue<char>();
//                 diff = 0;
//             }
//             else if(diff == 0)
//                 maxLen = max(maxLen, (int)que.size());
//         }
//         reverse(s.begin(), s.end());
//         diff = 0;
//         que = queue<char>();
//         for(auto ch : s)
//         {
//             que.push(ch);
//             if(ch == '(') -- diff;
//             else ++ diff;

//             if(diff < 0)
//             {
//                 que = queue<char>();
//                 diff = 0;
//             }
//             else if(diff == 0)
//                 maxLen = max(maxLen, (int)que.size());
//         }

//         return maxLen;

//     }
// };
class Solution {
public:
    
    // stack
    // (()
    // ()))
    // ()()()
    int longestValidParentheses(string s) {

        stack<int> stk;
        int ret = 0, start = -1;
        for(int i = 0 ; i < s.size(); ++ i)
        {
            // 左括号入栈
            if(s[i] == '(') stk.push(i);
            else // 右括号匹配
            {   
                // 此时没有左括号与之匹配，则该右括号是多余的
                // 新的可能的序列，从i后开始，这里把i放进去，则后面求长度不用-1
                if(stk.empty())
                    start = i;
                else
                {
                    stk.pop(); // 弹出左括号

                    // 左括号还有左括号，则一定和该左括号相连
                    if(!stk.empty())
                        ret = max(ret, i - stk.top());
                    // 没有左括号，则该次匹配的合法串可以和之前的连接在一起
                    else
                        ret = max(ret, i - start);
                }
                
            }
        }

        return ret;
    }
};