class Solution {
public:
  
    int f(vector<int> &a, int idx, int prev,   vector<vector<int>> &dp){
        int n = a.size();
        if(idx == n) return 0;
        
        if(prev != -1 && dp[idx][prev] != -1) 
            return dp[idx][prev];
        
        int pick = INT_MIN;
        int not_pick = f(a, idx+1, prev, dp);
        if(prev == -1 || a[idx] > a[prev])
            pick = 1 + f(a, idx+1, idx, dp);
        
        if(prev  != -1) dp[idx][prev] = max(pick , not_pick);
        return  max(pick, not_pick);        
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(2500, vector<int>(2500, -1));
        return f(nums, 0, -1, dp);
    }
};