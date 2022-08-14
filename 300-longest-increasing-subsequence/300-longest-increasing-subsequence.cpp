class Solution {
public:
  
    int f(vector<int> &a, int idx, int prev, vector<vector<int>> &dp){
        int n = a.size();
        if(idx == n) return 0;
        
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        
        // not pick
        int ans = 0 + f(a, idx + 1, prev, dp);

        // pick
        if(prev == -1 || a[idx] > a[prev])
            ans = max(ans , 1 + f(a, idx + 1, idx, dp));
        
        return dp[idx][prev+1] = ans;        
    }

    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(nums, 0, -1, dp);
    }
};