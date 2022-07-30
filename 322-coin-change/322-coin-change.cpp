class Solution {
public:
    long helper(vector<int> &coins, int idx, int amt,  vector<vector<long>> &dp){
        if(amt == 0) return 0;
        if(idx < 0) return INT_MAX;
        if(dp[idx][amt] != -1) return dp[idx][amt];
        if(amt % coins[idx] == 0) return dp[idx][amt] = amt / coins[idx];
        if(idx == 0) return dp[idx][amt] = INT_MAX;
        
        long ntake =  0 + helper(coins, idx -1 , amt, dp);
        long take = INT_MAX;
        if(coins[idx] <= amt)
            take = helper(coins, idx, amt - coins[idx], dp);
        return dp[idx][amt] = min(take == INT_MAX ? take : take + 1, ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<vector<long>> dp(coins.size(), vector<long>(amount+1, -1));
        int n = coins.size();
        long res = helper(coins, n - 1, amount, dp);
        return res >= INT_MAX ? -1 : res;
    }
};