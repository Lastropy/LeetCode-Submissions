class Solution {
public:
    int f(vector<int> &a, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MIN;
        for(int k = i; k <= j; k++){
            int tmp = f(a, i, k-1, dp) + f(a, k+1, j, dp) + (a[i-1] * a[k] * a[j+1]);
            ans = max(ans, tmp);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+3, vector<int>(n+3, -1));
        return f(nums, 1, n, dp);
    }
};