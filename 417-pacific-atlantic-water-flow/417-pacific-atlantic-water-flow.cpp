class Solution {
public:
//     void connected(vector<vector<int>>& h, int i , int j, set<vector<int>> &s){
//         int m = h.size(), n = h[0].size();
//         if(i < 0 || j < 0 || j >= n || i >= m || h[i][j] == INT_MIN) return;
        
//         s.insert({i,j});
        
//         int ini = INT_MIN;
//         swap(h[i][j], ini);
//         if(i > 0 && h[i-1][j] >= ini)
//             connected(h, i-1, j, s);
        
//         if(j > 0 && h[i][j-1] >= ini)
//             connected(h, i, j-1, s);
        
//         if(j < n-1 && h[i][j+1] >= ini)
//             connected(h, i, j+1, s);
        
        
//         if(i < m-1 && h[i+1][j] >= ini)
//             connected(h, i+1, j, s);
        
//         swap(h[i][j], ini);

//     }

//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
//         int m = h.size(), n = h[0].size();
        
//         set<vector<int>> pac, atl;
        
//         vector<vector<int>> ans;
        
//         for(int i = 0; i < m; i++)
//             connected(h, i, 0, pac);

//         for(int j = 1; j < n; j++)
//             connected(h, 0, j, pac);

//         for(int i = 0; i < m; i++)
//             connected(h, i, n-1, atl);

//         for(int j = 0; j < n-1; j++)
//             connected(h, m-1, j, atl);
        
//         for(auto v: pac){
//             if(atl.find(v) != atl.end())
//                 ans.push_back(v);
//         }

//         return ans;
//     }
    
    void connected(vector<vector<int>> &h, int i , int j, int prev, vector<vector<int>> &ocean){
        int m = h.size(), n = h[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || h[i][j] < prev || ocean[i][j])
            return;
        
        ocean[i][j]++;
        
        connected(h, i-1, j, h[i][j], ocean);
        connected(h, i, j-1, h[i][j], ocean);
        connected(h, i+1, j, h[i][j], ocean);
        connected(h, i, j+1, h[i][j], ocean);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0)), atl(m, vector<int>(n, 0));
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < m; i++)
            connected(h, i, 0, INT_MIN, pac);

        for(int j = 0; j < n; j++)
            connected(h, 0, j, INT_MIN, pac);

        for(int i = 0; i < m; i++)
            connected(h, i, n-1, INT_MIN, atl);

        for(int j = 0; j < n; j++)
            connected(h, m-1, j, INT_MIN, atl);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
         
    }
};