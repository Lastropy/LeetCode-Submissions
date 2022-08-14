class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int lim = 0; lim <= 2; lim++){
                    if(lim == 0) 
                        dp[idx][buy][lim] = 0;
                    else if(buy){
                        int b = -p[idx] + dp[idx+ 1][0][lim];
                        int nb = 0 + dp[idx + 1][1][lim];
                        dp[idx][buy][lim] = max(b, nb);   
                    }
                    else{
                        int s = p[idx] + dp[idx+ 1][1][lim-1];
                        int ns = 0 + dp[idx + 1][0][lim];
                        dp[idx][buy][lim] = max(s, ns);  
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};