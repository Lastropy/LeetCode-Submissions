class Solution {
private:
    vector<int> dp;
    int mod = 1e9 + 7;
    int goodStringsWithSizeEqualTo(int k, int &z, int &o){
        if(k == 0) return 1;
        if(k< 0 || (k < z && k < o)) return 0;
        if(dp[k] != -1) return dp[k];
        
        int ans = 0;
        if(k - z >= 0) ans +=  goodStringsWithSizeEqualTo(k-z, z, o);
        ans %= mod;
        if(k - o >= 0) ans +=  goodStringsWithSizeEqualTo(k-o, z, o);
        ans %= mod;
        return dp[k] = ans; 
    }
public:
    int countGoodStrings(int l, int h, int z, int o) {
        dp = vector<int>(h+1, -1);
        dp[0] = 1;
          
        int ans = 0;
        for(int i = l; i <= h; i++){
            goodStringsWithSizeEqualTo(i, z, o);
        
                ans += dp[i];
                ans %= mod;
    
        }
        return ans;
        
    }
};