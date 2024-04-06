class Solution {
public:
    bool canFill(vector<vector<char>> &board, int i, int j, char c){
        for(int idx = 0; idx < 9; idx++){
            if(board[idx][j] == c) {
                return false;
            }
            if(board[i][idx] == c){
                return false;
            }
            
            if(board[3 * (i / 3) + (idx / 3)][3 * (j / 3) + (idx % 3)] == c){
                return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(canFill(board, i, j, c)){
                            board[i][j] = c;
                            if(solve(board) == true) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;       
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};