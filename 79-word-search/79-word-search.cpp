class Solution {
public:
    bool find(vector<vector<char>>& board, int i, int j, int st, string &word, vector<vector<bool>> &vis){
        if(vis[i][j]) return false;
        if(st == word.size()) return true;
        if(st == word.size() -1  && board[i][j] == word[st]) return true;
        if(word[st] != board[i][j]) return false;
        vis[i][j] = true;
        if( i > 0 && find(board, i-1, j , st+1, word, vis)) return true;
        if( j > 0 && find(board, i, j-1, st+1, word, vis)) return true;
        if(j < board[0].size()-1 && find(board,i, j+1, st+1, word, vis)) return true;
        if(i < board.size()-1 && find(board,i+1, j, st+1, word, vis)) return true;
        vis[i][j] = false;
        return false;
            
}
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m , false));
        vector<pair<int,int>> pos;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(find(board, i, j, 0, word, vis))
                    return true;
            }
        }
        return false;
    }
};