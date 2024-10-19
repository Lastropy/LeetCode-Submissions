class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &a, int idx, int t){
        if(t == 0) return 0;
        if(idx == a.size()) return 1e9;
        if(dp[idx][t] != -1) return dp[idx][t];
        int notTake = 0 + solve(a, idx + 1, t);
        int take = 1e9;
        if(t >= a[idx]) take = 1 + solve(a, idx, t - a[idx]);
        return dp[idx][t] = min(take, notTake);
    }
    
    int coinChange(vector<int>& a, int t) {
        dp.resize(a.size(), vector<int>(t + 1, -1));
        int ans = solve(a, 0 , t);
        if(ans == 1e9) return -1;
        return ans;
    }
};