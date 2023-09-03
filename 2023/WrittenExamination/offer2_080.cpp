class Solution {
private:
    vector<vector<int>> ans;
    int n, k;
    void sol(int cnt, int pos, vector<int>& tmp)
    {
        if(cnt == k)
        {
            ans.push_back(tmp);
            return ;
        }

        for(int i = pos + 1; i <= n; ++ i)
        {
            tmp.push_back(i);
            sol(cnt + 1, i, tmp);
            tmp.pop_back();
        }

    }
public:
    vector<vector<int>> combine(int n, int k) {

        this->n = n;
        this->k = k;
        
        vector<int> tmp;
        sol(0, 0, tmp);

        return ans;
    }
};