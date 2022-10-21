// 给定一个二维数组board，代表棋盘，其中元素为1的代表是当前玩家的棋子，0表示没有棋子，-1代表是对方玩家的棋子。
// 当一方棋子在横竖斜方向上有连成排的及获胜（及井字棋规则)，返回当前玩家是否胜出。

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        bool sta = false;
        for(int i = 0; i < 3; ++ i)
        {
            if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == 1)
            {
                sta = true;
            }
        }
        for(int i = 0; i < 3; ++ i)
        {
            if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == 1)
            {
                sta = true;
            }
        }
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == 1)
        {
            sta = true;
        }
        if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == 1)
        {
            sta = true;
        }
        return sta;
    }
};
