class Solution {
public:
     bool palin(string &s, int st, int e){
        if(st >= e) return true;
        return (s[st] == s[e]) && palin(s, st + 1, e - 1);
 
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
        vector<int> dp(s.size(), -1);
        // vector<vector<int>> is(s.size(), vector<int>(s.size(), - 1));
        // int res = f(s, 0, dp, is);
        int res = f(s, 0, dp);

        int n = s.size();
        return min(n - 1, res);
    }
};