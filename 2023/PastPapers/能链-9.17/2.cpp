// https://www.nowcoder.com/questionTerminal/14bcbcb7ae3c40c9bdbc5a0861361c29
#include <vector>
#include <string>
using namespace std;

class Solution {

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param board string字符串vector 
     * @param word string字符串 
     * @return bool布尔型
     */
private:

    int dxy[5] = {0,1,0,-1,0};
    vector<vector<bool>> st;
    vector<string> board;
    int n, m;
    string str;
    bool dfs(int x, int y, int idx)
    {
        if(board[x][y] != str[idx])
            return false;
        if(idx == str.size() - 1)
            return true;
        
        st[x][y] = true;
        for(int k = 0; k < 4; ++ k)
        {
            int nx = x + dxy[k];
            int ny = y + dxy[k + 1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !st[nx][ny])
            {
                if(dfs(nx, ny, idx + 1))
                    return true;
            }
        }
        st[x][y] = false;

        return false;
    }
public:
    bool exist(vector<string>& board, string word) {
        
        //暴力DFS

        this->board = board;
        n = board.size();
        m = board[0].size();
        str = word;
        st = vector<vector<bool>>(n, vector<bool>(m, false));  
        
        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < m; ++ j)
            {
                if(board[i][j] != word[0])
                    continue;
                
                if(dfs(i, j, 0))
                    return true;
            }

        return false;
    }
};