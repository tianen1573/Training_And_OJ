#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int cal(const string& str, int tar)
{
    stack<int> num;
    stack<char> op;
    
    for(int i = 0; i < str.size(); ++ i)
    {
        if(str[i] == '+')
        {
            if(op.size())
            {
                int left = num.top();
                num.pop();
                int right = num.top();
                num.pop();
                char oopp = op.top();
                op.pop();
                int val;
                switch(oopp)
                {
                    case '+':
                        val = left + right;
                        break;
                    case '*':
                        val = left * right;
                        break;
                }
                if(val > tar)
                    return val;
                num.push(val);
            }
            op.push('+');
        }
        else if(str[i] == '*')
        {
            if(op.size() && op.top() == '*')
            {
                int left = num.top();
                num.pop();
                int right = num.top();
                num.pop();
                op.pop();
                int val = left * right;
                if(val > tar)
                    return val;
                num.push(val);
            }
            op.push('*');
        }
        else
        {
            int val = 0;
            while(i < str.size() && str[i] != '+' && str[i] != '*')
                val = val * 10 + (str[i++] - '0');
            -- i;
            if(val > tar)
                return val;
            num.push(val);
        }
    }
    
    while(op.size())
    {
        int left = num.top();
        num.pop();
        int right = num.top();
        num.pop();
        char oopp = op.top();
        op.pop();
        int val;
        switch(oopp)
        {
            case '+':
                val = left + right;
                break;
            case '*':
                val = left * right;
                break;
        }
        if(val > tar)
            return val;
        num.push(val);
    }
    
    return num.top();
}

int main()
{
    int n = 0;
    cin >> n;
    while(n --)
    {
        string mother;
        cin >> mother;
        string left = mother.substr(0, mother.find('='));
        string right = mother.substr(mother.find('=') + 1);
        int leftVal = cal(left, 1000000009);
        int rightVal = cal(right, 1000000009);
        string tmp;
        int tar;
        
        if(leftVal == rightVal)
        {
            cout <<"Yes\n";
            continue;
        }
        else if(leftVal > rightVal)
        {
            tar = leftVal;
            tmp = right;
        }
        else
        {
            tar = rightVal;
            tmp = left;
        }
        bool flag = true;
        for(int i = 0; i <= tmp.size(); ++ i)
        {
            int r = 9, l = 0;
            if(i == 0 || tmp[i - 1] == '+' || tmp[i - 1] == '*')
                ++ l;
            int ans;
            for(; l <= r; ++ l)
            {
                char ch = '0' + l;
                ans = cal(tmp.substr(0, i - 0) + ch + tmp.substr(i), tar);
                if(ans >= tar)
                    break;
            }
            if(ans == tar)
            {
                cout << "Yes\n";
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "No\n";
    }
    
    
    return 0;
}