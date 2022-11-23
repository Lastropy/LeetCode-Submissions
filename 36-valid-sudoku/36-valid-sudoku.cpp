class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> s1(10, 0), s2(10, 0);
        vector<vector<int>> s3(9, vector<int>(10, 0));
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(isdigit(board[i][j])){
                    int key = ((i / 3) * 3 + (j / 3));
                    int val = board[i][j] - '0';
                    if(s1[val] || s3[key][val])
                        return false;
                    s1[val] = s3[key][val] = 1;
                }
                if(isdigit(board[j][i])){
                    int val2 = board[j][i] - '0';
                    if(s2[val2])
                        return false;
                    s2[val2] = 1;
                } 
            }
            s1 = s2 = vector<int>(10, 0);
        }
        return true;
    }
};