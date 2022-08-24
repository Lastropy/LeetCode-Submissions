class Solution {
public:
    int f(vector<int> &a, int idx, int k, vector<int> &dp){
        int n = a.size();

        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int mx = INT_MIN;
        int ans = INT_MIN;

        
        for(int j = idx; j < min(n, idx + k); j++){
            mx = max(mx, a[j]);
            int sum = (mx * (j - idx + 1)) + f(a, j + 1, k, dp);
            ans = max(ans, sum);
        }

        return dp[idx] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        // vector<int> dp(a.size() + 1, -1);
        // return f(a, 0, k, dp);

        int n = a.size();
        vector<int> dp(n + 1, 0);

        for(int idx = n - 1; idx >= 0; idx--){
            int mx = INT_MIN;
            int ans = INT_MIN;


            for(int j = idx; j < min(n, idx + k); j++){
                mx = max(mx, a[j]);
                int sum = (mx * (j - idx + 1)) + dp[j+1];
                ans = max(ans, sum);
            }
            
            dp[idx] = ans;
        }
        
        return dp[0];
    }
};