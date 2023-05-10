class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int count = 1;
        int rmin = 0, rmax = n-1, cmin = 0, cmax = n-1;
        while(count <= n * n){
            for(int i = cmin; i <= cmax && count <= n * n; i++ )
                ans[rmin][i] = count++;
            rmin++;
            for(int i = rmin; i <= rmax && count <= n * n; i++)
                ans[i][cmax] = count++;
            cmax--;
            for(int i = cmax; i >= cmin && count <= n * n; i--)
                ans[rmax][i] = count++;
            rmax--;
            for(int i = rmax; i >= rmin && count <= n * n; i--)
                ans[i][cmin] = count++;
            cmin++;
        }
        return ans;
    }
};