class Solution {
private:
    int tar_row;
    void equate(int r, vector<vector<double>> &dp){
        for(int i = 0; i <= r; i++){
            if(dp[r][i] >= 1){
                double excess = dp[r][i] -1;
                dp[r + 1][i] += excess/2.0;                
                dp[r + 1][i+1] += excess/2.0;
                dp[r][i] = 1;
            }
        }
        if(r < tar_row) equate(r + 1, dp);
    }
public:
    double champagneTower(int poured, int r, int g) {
        vector<vector<double>> dp(101, vector<double>(101, 0.00));
        tar_row = r;
        dp[0][0] = poured;
        equate(0, dp);
        return dp[r][g];
    }
};