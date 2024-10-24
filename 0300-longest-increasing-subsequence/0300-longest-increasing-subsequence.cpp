class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& a, int idx, int prev_idx = -1) {
        if(idx == a.size()) return 0;
        if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];
        int notTake = 0 + solve(a, idx + 1, prev_idx);
        int take = 0;
        if(prev_idx == -1 || a[idx] > a[prev_idx]){
            take = 1 + solve(a, idx + 1, idx);
        }
        return dp[idx][prev_idx + 1] = max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& a) {
        dp.resize(a.size() + 1, vector<int>(a.size() + 1, -1));
        return solve(a, 0);
    }
};