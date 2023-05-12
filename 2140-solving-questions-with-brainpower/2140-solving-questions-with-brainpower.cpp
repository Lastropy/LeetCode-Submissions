class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n + 1, 0);
        
        for(int i = n - 1; i >= 0; i--){
            long long take = q[i][0] + (q[i][1] + i + 1 <=n ? dp[q[i][1] + i + 1]: 0);
            long long skip = max(dp[i], dp[i+1]);
            dp[i] = max(take, skip);
        }
        return dp[0];
    }
};