class Solution {
public:
    int maxScore(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        long long ans = INT_MIN;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int mn = INT_MAX;
                if(i) mn = min(mn, a[i - 1][j]);
                if(j) mn = min(mn, a[i][j - 1]);
                ans = max(ans, (long long)(a[i][j] - mn));
                a[i][j] = min(mn, a[i][j]);
            }
        }
        return ans;
    }
};