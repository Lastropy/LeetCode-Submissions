class Solution {
private:
    void equate(int r, vector<vector<double>> &dp){
        if(r > dp.size() - 2) return;
        for(int i = 0; i <= r; i++){
            if(dp[r][i] >= 1){
                double excess = dp[r][i] -1;
                dp[r + 1][i] += excess/2.0;                
                dp[r + 1][i+1] += excess/2.0;
                dp[r][i] = 1;
            }
        }
        equate(r + 1, dp);
    }
public:
    double champagneTower(int poured, int r, int g) {
        vector<vector<double>> dp(r+2, vector<double>(r+2, 0.00));
        dp[0][0] = poured;
        equate(0, dp);
        return dp[r][g];
    }
};