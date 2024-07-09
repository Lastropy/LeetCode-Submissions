class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> xCount(n, vector<int>(m, 0)), yCount(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                auto curr = g[i][j];
                xCount[i][j] += (g[i][j] == 'X');        
                if(i > 0) xCount[i][j] += xCount[i-1][j];                
                if(j > 0) xCount[i][j] += xCount[i][j-1];
                if(i >0 && j >0) xCount[i][j] -= xCount[i-1][j-1];

                yCount[i][j] += (g[i][j] == 'Y');
                if(i > 0) yCount[i][j] += yCount[i-1][j];                
                if(j > 0) yCount[i][j] += yCount[i][j-1];
                if(i >0 && j >0) yCount[i][j] -= yCount[i-1][j-1];
                
                if(xCount[i][j] == yCount[i][j] && xCount[i][j] >0) ans++;
            }
        }
        return ans;
    }
};