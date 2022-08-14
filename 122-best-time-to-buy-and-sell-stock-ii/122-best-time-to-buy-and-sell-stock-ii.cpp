class Solution {
public:
//     int f(vector<int> &p, int idx, bool buy, vector<vector<int>> &dp){
//         int n = p.size();
//         if(idx == n) return 0;
//         if(dp[idx][buy] != -1) return dp[idx][buy];
//         int ans = 0;
//         if(buy){
//             int b = -p[idx] + f(p, idx+1, 0, dp);
//             int nb = 0 + f(p, idx+1, 1, dp);
//             ans = max(b, nb);
//         }
//         else{
//             int s = p[idx] + f(p, idx+1, 1, dp);
//             int ns = 0 + f(p, idx+1, 0, dp);
//             ans = max(s, ns);
//         }
//         return dp[idx][buy] = ans;       
//     }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int idx = n-1; idx >= 0; idx--){
            int b = -p[idx] + dp[idx+1][0];
            int nb = 0 + dp[idx+1][1];
            int s = p[idx] + dp[idx+1][1];
            int ns = 0 + dp[idx+1][0];
            dp[idx][0] = max(s, ns);
            dp[idx][1] = max(b, nb);
        }
        return dp[0][1];
    }
};