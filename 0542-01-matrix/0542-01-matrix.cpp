class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(g[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        int stp = 0;
        while(!q.empty()){
            int siz = q.size();
            for(int k = 0; k < siz; k++){
                int i = q.front().first, j = q.front().second; q.pop();
                // cout << i << " | " << j << " => "<<stp << endl;
                ans[i][j] = stp;
                if(i > 0 && g[i - 1][j] == 1) {q.push({i-1, j}); g[i - 1][j] = -1;}
                if(j > 0 && g[i][j - 1] == 1) {q.push({i, j - 1}); g[i][j - 1] = -1;}
                if(i < m - 1 && g[i+1][j] == 1) {q.push({i+1, j}); g[i + 1][j] = -1;}
                if(j < n - 1 && g[i][j+1] == 1) {q.push({i, j+1}); g[i][j + 1] = -1;}
            }
            stp++;
        }
        return ans;

    }
};