class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& a, int idx){
        if(idx >= a.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = a[idx] + solve(a, idx + 2);
        int skip = 0 + solve(a, idx + 1);
        return dp[idx] = max(take, skip);
    }
    
    int rob(vector<int>& a) {
        int n = a.size();
        dp.resize(n+1, -1);
        dp[n] = 0;
        return solve(a, 0);
    }
};