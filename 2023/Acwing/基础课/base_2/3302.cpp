#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

stack<char> _op;
stack<int> _num;
unordered_map<char, int> Map;


void cal()
{
    char op = _op.top();
    _op.pop();
    
    
    int rig = _num.top();
    _num.pop();
    int left = _num.top();
    _num.pop();
    
    
    int val;
    switch(op)
    {
        case '+':
            val = left + rig;
            break;
        case '-':
            val = left - rig;
            break;
        case '*':
            val = left * rig;
            break;
        case '/':
            val = left / rig;
    }
    
    _num.push(val);
}

int main()
{
    Map['-'] = 1;
    Map['+'] = 1;
    Map['*'] = 2;
    Map['/'] = 2;
    
    string str;
    cin >> str;
    
    for(int i = 0; i < str.size(); ++ i)
    {
        if(str[i] == '(') _op.push('(');
        else if(str[i] == ')')
        {
            while(!_op.empty() && _op.top() != '(') cal();
            _op.pop();
        }
        else
        {
            if(isdigit(str[i]))
            {
                int j = i;
                int u = 0;
                while(j < str.size() && isdigit(str[j])) u = u*10 + (str[j ++] - '0');
                
                _num.push(u);
                i = j - 1;
            }
            else
            {
                if(i > 0 && (str[i - 1]) == '(' || str[i - 1] == '+' || str[i - 1] == '-')
                {
                    _num.push(0);
                }
                
                while(!_op.empty() && _op.top() != '(')
                {
                    if(Map[_op.top()] >= Map[str[i]])
                        cal();
                    else break;
                }
                
                _op.push(str[i]);
            }
        }
        
    }
    
    while(!_op.empty()) cal();
    
    cout << _num.top();
    
    return 0;
}