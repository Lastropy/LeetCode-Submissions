class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        unordered_map<int, int> r0, c0;
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                if(mat[i][j]==0){
                    r0[i] = 1;
                    c0[j] = 1;
                }
            }
        }
        for(auto [k,v]: r0){
            for(int i = 0; i< m; i++){
                mat[k][i] = 0;
            }
        }
        for(auto [k,v]: c0){
            for(int i = 0; i< n; i++){
                mat[i][k] = 0;
            }
        }
    }
};