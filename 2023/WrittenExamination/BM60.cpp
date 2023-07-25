class Solution {
public:
    
    vector<string> res;

    void dfs(string tmp, int l, int r)
    {
        if(r < l) return ;
        if(r == 0)
        {
            if(l == 0)
            {
                res.push_back(std::move(tmp));
            }
            return ;
        }
        
        if(l > 0)
        {
            dfs(tmp + '(', l - 1, r);
        }
        if(r > 0)
        {
            dfs(tmp + ')', l, r - 1);
        }

    }
    vector<string> generateParenthesis(int n) {
        // write code here

        dfs(string(), n, n);

        return res;
    }
};