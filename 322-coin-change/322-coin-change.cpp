class Solution {
public:
    int helper(vector<int> &coins, int idx, int amt,  vector<vector<int>> &dp){
        if(amt == 0) return 0;
        if(idx < 0) return INT_MAX;
        if(dp[idx][amt] != -1) return dp[idx][amt];
        if(amt % coins[idx] == 0) return dp[idx][amt] = amt / coins[idx];
        if(idx == 0) return dp[idx][amt] = INT_MAX;
        
        int ntake =  0 + helper(coins, idx -1 , amt, dp);
        int take = INT_MAX;
        if(coins[idx] <= amt)
            take = helper(coins, idx, amt - coins[idx], dp);
        return dp[idx][amt] = min(take == INT_MAX ? take : take + 1, ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int n = coins.size();
        int res = helper(coins, n - 1, amount, dp);
        return res == INT_MAX ? -1 : res;
    }
};