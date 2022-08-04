class Solution {
public:
      bool palin(string &s, int i, int j){
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            i++; j--;
        }
        return true; 
    }
    int f(string &s, int st, vector<int> &dp){
        if(st >= s.size() - 1) return 0;
        if(dp[st] != -1) return dp[st];
        
        int curr;
        int ans = INT_MAX;
        for(int i  = st; i < s.size();i++){
            if(palin(s, st, i)){
                curr =  (i != s.size() - 1 ) + f(s, i + 1, dp);
                ans = min(curr, ans);
            }
        }
        return dp[st] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        int res = f(s, 0, dp);
        return min(n - 1, res);
    }
};