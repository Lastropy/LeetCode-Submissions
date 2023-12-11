class NumMatrix {
private: 
    vector<vector<int>> pref;
public:
    NumMatrix(vector<vector<int>>& a) {
        int r = a.size(), c = a.size() ? a[0].size(): 0;
        pref = vector<vector<int>> (r + 1, vector<int>(c + 1, 0));
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <=c ; j++){
                int curr_ele = a[i - 1][j - 1];
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + curr_ele;
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return pref[r2+1][c2+1] - pref[r2 + 1][c1] - pref[r1][c2 + 1] + pref[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */