class Solution {
public:
    bool palin(string &s, int st, int e, vector<vector<int>> &is){
        if(is[st][e] != -1) return is[st][e];
        int i = st, j = e;
        while(i < j)
        {
            if(s[i] != s[j])
                return is[st][e] = false;
            i++; j--;
        }
        return is[st][e] = true; 
    }
    int f(string &s, int st, vector<int> &dp, vector<vector<int>> &is){
        if(st >= s.size() - 1) return 0;
        if(dp[st] != -1) return dp[st];
        
        int curr = -1;
        int ans = INT_MAX;
        for(int i  = st; i < s.size();i++){
            if(palin(s, st, i, is)){
                curr =  (i != s.size() - 1 ) + f(s, i + 1, dp, is);
                ans = min(curr, ans);
            }
        }
        return dp[st] = ans;
    }
    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        vector<vector<int>> is(s.size(), vector<int>(s.size(), - 1));
        int res = f(s, 0, dp, is);
        int n = s.size();
        return min(n - 1, res);
    }
};