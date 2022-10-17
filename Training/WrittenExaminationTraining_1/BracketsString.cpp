

// ����һ���ַ���A���䳤��n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ�(ֻ�����������)��
// ��������:


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