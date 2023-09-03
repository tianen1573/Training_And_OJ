class Solution {

private:
    vector<string> ans;
    int n;
    void sol(int left, int rig, string tmp)
    {
        if(left == 0 && rig == 0)
        {
            ans.emplace_back(tmp);
            return ;
        }

        if(left)
            sol(left - 1, rig, tmp + '(');
        if(rig > left)
            sol(left, rig - 1, tmp + ')');
    }

public:
    vector<string> generateParenthesis(int n) {
        
        this->n = n;
        sol(n, n, "");

        return ans;
    }
};