class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(isdigit(board[i][j])){
                    if(s.find(board[i][j]) != s.end())
                        return false;
                    s.insert(board[i][j]);
                }
            }
            s.clear();
        }
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(isdigit(board[j][i])){
                    if(s.find(board[j][i]) != s.end())
                        return false;
                    s.insert(board[j][i]);
                }
            }
            s.clear();
        }
        
        
        unordered_map<string, set<int>> mp;
        
        for(int i =0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(!isdigit(board[i][j])) continue;
                string key = to_string(i / 3) + to_string(j / 3);
                
                if(mp[key].find(board[i][j]) != mp[key].end())
                    return false;
                
                mp[key].insert(board[i][j]);
            }
        }
        
        
        
        
        return true;
        
    }
};