class Solution {
public:
    bool canPlaceQueen(vector<bool> &rows, vector<bool> &upper_diagonal, vector<bool> &lower_diagonal, int r, int c){
        if(rows[r] == true){
            return false;
        }
        
        if(lower_diagonal[r + c] == true){
            return false;
        }
        
        if(upper_diagonal[rows.size() - 1 + r - c] == true){
            return false;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans, vector<string> &board, vector<bool> &rows, vector<bool> &upper_diagonal, vector<bool> &lower_diagonal, int c = 0){
        if(c == board.size()){
            ans.push_back(board);
            return;
        }
        
        for(int r = 0; r < board.size(); r++){
            if(canPlaceQueen(rows, upper_diagonal, lower_diagonal, r, c)){
                board[r][c] = 'Q';
                rows[r] = true;
                upper_diagonal[(board.size() -1) + (r - c)] = true;
                lower_diagonal[r + c] = true;
                solve(ans, board,rows, upper_diagonal, lower_diagonal, c+1);
                board[r][c] = '.';
                rows[r] = false;
                upper_diagonal[(board.size() -1) + (r - c)] = false;
                lower_diagonal[r + c] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> rows(n, false), upper_diagonal(2 *n -1, false), lower_diagonal(2 *n - 1, false);
        vector<string> board(n, string(n, '.'));
        solve(ans, board, rows, upper_diagonal, lower_diagonal);
        return ans;
    }
};