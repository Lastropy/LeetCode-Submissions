class Solution {
public:
    bool canPlaceQueen(vector<string> &board, int r, int c){
        int cpyR = r;
        int cpyC = c;
        
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;
            c--;
        }
        
        r = cpyR;
        c = cpyC;
        
        while(r < board.size() && c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r++;
            c--;
        }
        
        r = cpyR;
        c = cpyC;
        
        while(c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            c--;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans, vector<string> &board, int c = 0){
        if(c == board.size()){
            ans.push_back(board);
            return;
        }
        
        for(int r = 0; r < board.size(); r++){
            if(canPlaceQueen(board, r, c)){
                board[r][c] = 'Q';
                solve(ans, board, c+1);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(ans, board);
        return ans;
    }
};