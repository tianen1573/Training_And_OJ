class Solution {
public:
    bool st[9][9] = {false};
    bool dfs(int row, int col, int pos)
    {
        if(pos == len) return true;
        for(int i = 0;i < 4; ++ i)
        {
            if(row + dec[i][0] >= R || col + dec[i][1] >= C 
            || row + dec[i][0] < 0 || col + dec[i][1] < 0) continue;//越界
            if(st[row + dec[i][0]][col + dec[i][1]]) continue;//字符已经被使用
            if((*vec)[row + dec[i][0]][col + dec[i][1]] != (*str)[pos]) continue;//不匹配

            st[row + dec[i][0]][col + dec[i][1]] = true;
            if(dfs(row + dec[i][0], col + dec[i][1], pos + 1)) return true;
            st[row + dec[i][0]][col + dec[i][1]] = false;
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        vec = &board;
        str = &word;
        len = word.size();
        R = board.size(), C = board[0].size();

        for(int r = 0; r < R; ++ r)
            for(int c = 0; c < C; ++ c)
            {
                if(board[r][c] == word[0])
                {
                    st[r][c] = true;
                    if(dfs(r, c, 1)) return true;
                    st[r][c] = false;
                }
            }
        
        return false;
        
    }
private:
    vector<vector<char>> *vec;
    int R, C;
    string *str;
    int dec[4][2] = {0,-1, -1,0, 0,1, 1,0};
    int len;
};