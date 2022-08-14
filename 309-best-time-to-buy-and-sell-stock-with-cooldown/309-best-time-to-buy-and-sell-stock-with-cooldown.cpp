class Solution {
public:
    int maxProfit(vector<int>& p) {
        bool cool_down = 0;
        int n = p.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, 0)));
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cool_down = 0; cool_down <= 1; cool_down++){
                    if(buy){
                        int b = -p[idx] + dp[idx + 1][0][0]; 
                        int nb = 0 + dp[idx + 1][1][0];

                        if(cool_down) dp[idx][buy][cool_down] = nb;
                        else dp[idx][buy][cool_down] = max(b, nb);
                    }
                    else{
                        int s = p[idx] + dp[idx+1][1][1];
                        int ns = 0 + dp[idx+1][0][0];
                        dp[idx][buy][cool_down] = max(s, ns);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};