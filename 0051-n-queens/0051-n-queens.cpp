class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // column check
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') return false;
        }

        // left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }

        // right diagonal
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void nqueen(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++) {
            if(isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nqueen(board, row + 1, n, ans);
                board[row][j] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nqueen(board, 0, n, ans);
        return ans;
    }
};