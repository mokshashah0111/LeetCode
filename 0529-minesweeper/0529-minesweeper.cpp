class Solution {
    bool isValid(vector<vector<char>>& board, int row, int col){
        return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0], col = click[1];
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return board;
        }

        queue<pair<int, int>> q;
        q.emplace(row, col);

        int delrow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delcol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (board[r][c] != 'E') continue;

            int mines = 0;
            for (int d = 0; d < 8; d++) {
                int nr = r + delrow[d];
                int nc = c + delcol[d];
                if (isValid(board, nr, nc) && board[nr][nc] == 'M') {
                    mines++;
                }
            }

            if (mines > 0) {
                board[r][c] = '0' + mines;
            } else {
                board[r][c] = 'B';
                for (int d = 0; d < 8; d++) {
                    int nr = r + delrow[d];
                    int nc = c + delcol[d];
                    if (isValid(board, nr, nc) && board[nr][nc] == 'E') {
                        q.emplace(nr, nc);
                    }
                }
            }
        }

        return board;
    }
};
