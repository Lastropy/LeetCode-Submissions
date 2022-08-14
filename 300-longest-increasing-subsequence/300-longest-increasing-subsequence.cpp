class Solution {
public:
  
    int f(vector<int> &a, int len, int prev, vector<vector<int>> &dp){
        int n = a.size();
        if(len > n) return 0;
        
        if(dp[len][prev] != -1) return dp[len][prev];
        
        // not pick
        int ans = 0 + f(a, len + 1, prev, dp);

        // pick
        if(prev == 0 || a[len - 1] > a[prev - 1])
            ans = max(ans , 1 + f(a, len + 1, len, dp));
        
        return dp[len][prev] = ans;        
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(2501, vector<int>(2501, -1));
        return f(nums, 1, 0, dp);
    }
};