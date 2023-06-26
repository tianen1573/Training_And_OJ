
#include <cctype>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */

    map<char, int> Map;
    void comp() {

        int ans;

        auto op = _opStk.top();
        _opStk.pop();

        auto rig = _numStk.top();
        _numStk.pop();
        auto left = _numStk.top();
        _numStk.pop();

        switch (op) {
            case '+':
                ans = left + rig;
                break;
            case '-':
                ans = left - rig;
                break;
            case '*':
                ans = left * rig;
        }

        _numStk.push(ans);

    }
    int solve(string str) {
        // write code here
        Map['-'] = 1;
        Map['+'] = 1;
        Map['*'] = 2;

        int len = str.size();

        string num;
        for (int i = 0; i < len; ++ i) {
            if (str[i] == '(') _opStk.push(str[i]);//左括号入栈
            else if (str[i] == ')') //右括号直接计算
            {
                while (_opStk.top() != '(') 
                {
                    comp();
                }
                _opStk.pop();//左括号出栈
            } 
            else 
            {
                if (isdigit(str[i])) //数字
                {
                    int u = 0;
                    int j = i;
                    while (j < len && isdigit(str[j])) u = u * 10 + (str[j++] - '0');

                    _numStk.push(u);
                    i = j - 1;
                } 
                else //op
                {   
                    //出现连续的运算符时，压一个0进栈，避免(-0+1)出现
                    if (i > 0 && (str[i - 1] == '(' || str[i - 1] == '+' || str[i - 1] == '-')) 
                    {
                        _numStk.push(0);
                    }

                    //运算符栈有内容
                    while (!_opStk.empty() && _opStk.top() != '(') 
                    {
                        
                        //比较优先级
                        if (Map[_opStk.top()] >= Map[str[i]]) 
                        {
                            comp();
                        } 
                        else 
                        {
                            break;
                        }
                    }

                    _opStk.push(str[i]);
                }
            }
        }
        
        while (!_opStk.empty() && _opStk.top() != '(') comp();

        return _numStk.top();

    }

    stack<char> _opStk;
    stack<int> _numStk;
};