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
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() + 1, -1);
        return f(arr, 0, k, dp);
    }
};