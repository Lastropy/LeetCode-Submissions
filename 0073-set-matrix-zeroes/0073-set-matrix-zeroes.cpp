class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        bool r0 = false,c0 = false;
        
        for(int i = 0; i < n && !r0; i++) r0 = (mat[i][0] == 0);
        for(int i = 0; i < m && !c0; i++) c0 = (mat[0][i] == 0);
        
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                if(mat[i][j] == 0) 
                    mat[i][0] = 0, mat[0][j] = 0;
        
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m && mat[i][0] == 0; j++)
                mat[i][j] = 0;
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n && mat[0][i] == 0; j++)
                mat[j][i] = 0;
            
        for(int i = 0; i < n && r0; i++) mat[i][0] = 0;        
        for(int i = 0; i < m && c0; i++) mat[0][i] = 0;        
    }
};