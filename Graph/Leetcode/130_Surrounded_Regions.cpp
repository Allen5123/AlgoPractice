//2021/8/6
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m_ = board.size();
        n_ = board.front().size();
        for (int i = 0; i < n_; ++i) { //find all connected components which connected with horizontal edge
            if (board[0][i] == 'O')
                Dfs(board, make_pair(0, i));
            if (board[m_-1][i] == 'O')
                Dfs(board, make_pair(m_ - 1, i));
        }
        for (int i = 0; i < m_; ++i) { //find all connected components which connected with vertical edge
            if (board[i][0] == 'O')
                Dfs(board, make_pair(i, 0));
            if (board[i][n_-1] == 'O')
                Dfs(board, make_pair(i, n_ - 1));
        }
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
                else {}
            }
        }
    }
private:
    int m_, n_, dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void Dfs(vector<vector<char>> &board, const pair<int, int> &coor) const
    {
        if (coor.first < 0 || coor.first >= m_ || coor.second < 0 || coor.second >= n_) { return; }
        if (board[coor.first][coor.second] == 'O') {
            board[coor.first][coor.second] = 'S';
            for (const auto &dir : dirs) {
                Dfs(board, make_pair(coor.first + dir[0], coor.second + dir[1]));
            }
        }
    }
};