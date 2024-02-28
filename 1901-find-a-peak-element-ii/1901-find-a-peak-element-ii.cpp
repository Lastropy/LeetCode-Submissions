class Solution {
public:
    int rowOfMaxEleInCol(vector<vector<int>>& g, int c, int m, int n){
        int ans = INT_MIN;
        int idx = -1;
        for(int i = 0; i < m; i++){
            if(g[i][c] > ans){
                ans = g[i][c];
                idx = i;
            }
        }
        return idx;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        int s = 0, e = n - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            int rowOfMaxElementInCol = rowOfMaxEleInCol(g, mid, m, n);
            if(((mid == 0) || (g[rowOfMaxElementInCol][mid] > g[rowOfMaxElementInCol][mid - 1])) && ((mid == n-1) || (g[rowOfMaxElementInCol][mid] > g[rowOfMaxElementInCol][mid + 1]))){
                return {rowOfMaxElementInCol, mid};
            } else if((mid > 0) && (g[rowOfMaxElementInCol][mid] < g[rowOfMaxElementInCol][mid - 1])) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return {-1, -1};
    }
};