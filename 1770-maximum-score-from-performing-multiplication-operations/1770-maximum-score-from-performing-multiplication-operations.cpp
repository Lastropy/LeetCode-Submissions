class Solution {
public:
    int f(vector<int>& a, int s, vector<int>& b, int used, vector<vector<int>> &dp){
        int m = b.size();
        int n = a.size();

        if(used == m) return 0;
        if(dp[s][used] != -1e9) return dp[s][used];
        
        int takeStart = a[s] * b[used] + f(a, s+1 , b , used + 1 ,  dp);
        int takeEnd = a[(n-1) - (used - s)] * b[used] + f(a, s, b, used + 1, dp);
        
        return dp[s][used] = max(takeStart, takeEnd);
    }
    int maximumScore(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(m, vector<int>(m, -1e9));

        int ans = f(a, 0, b, 0, dp);

        return ans;
    }
};