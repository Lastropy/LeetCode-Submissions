class Solution {
public:
    bool solve(vector<int> &a, int idx, vector<int> &dp){
        if(idx >= a.size()-1) return true;
        if(dp[idx] != -1) return dp[idx];
        
        dp[idx] = 0;
        for(int ss = 1; ss <= a[idx]; ss++){
            dp[idx] = solve(a, idx+ss, dp);
            if(dp[idx] == 1) break;
        }
        return dp[idx];
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        bool ans = solve(nums, 0, dp);
        return ans;
    }
};