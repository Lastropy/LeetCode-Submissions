class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& a, int idx, int t) {
        if(t == 0) return 1;
        if(idx == a.size() || t < 0) return 0;
        if(dp[idx][t] != -1) return dp[idx][t];
        int notTake = solve(a, idx + 1, t);
        int take = 0;
        if(t >= a[idx]) take = solve(a, idx, t - a[idx]);
        return dp[idx][t] = take + notTake;
    }
    
    int change(int t, vector<int>& a) {
        dp.resize(a.size(), vector<int>(t+ 1, -1));
        return solve(a, 0, t);
    }
};