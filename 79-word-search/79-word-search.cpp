class Solution {
public:
    bool find(vector<vector<char>>& board, int i, int j, int st, string &word){
        if(board[i][j] == '*') return false;
        if(st == word.size()) return true;
        if(st == word.size() -1  && board[i][j] == word[st]) return true;
        if(word[st] != board[i][j]) return false;
        char c = board[i][j];
        board[i][j] = '*';
        if( i > 0 && find(board, i-1, j , st+1, word)) return true;
        if( j > 0 && find(board, i, j-1, st+1, word)) return true;
        if(j < board[0].size()-1 && find(board,i, j+1, st+1, word)) return true;
        if(i < board.size()-1 && find(board,i+1, j, st+1, word)) return true;
        board[i][j] = c;
        return false;
            
}
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(find(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};