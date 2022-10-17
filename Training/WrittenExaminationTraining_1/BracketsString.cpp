

// 给定一个字符串A和其长度n，请返回一个bool值代表它是否为一个合法的括号串(只能由括号组成)。
// 测试样例:


class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        int left = 0;
        
        for(auto& ch : A)
        {
            if(ch != '(' && ch != ')')
            {
                return false;
            }
            if(ch == '(')
            {
                ++left;
            }
            else if(--left < 0)
            {
                return false;
            }
        }
        
        if(left)
        {
            return false;
        }
        
        
        return true;
    }
};