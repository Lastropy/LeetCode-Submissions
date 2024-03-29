class Solution {
public:
    bool solve(vector<int> &a, int idx, vector<int> &dp){
        if(idx == a.size()-1) return true;
        if(idx >= a.size() || a[idx] == 0) return false;
        if(dp[idx] != -1) return dp[idx];
        
        dp[idx] = 0;
        for(int ss = a[idx]; ss >= 0; ss--){
            dp[idx] = solve(a, idx+ss, dp);
            if(dp[idx]) break;
        }
        return dp[idx];
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        bool ans = solve(nums, 0, dp);
        return ans;
    }
};