class Solution {
private:
    bool isPalin(string &s, int i, int j){
        while(i < j)
            if(s[i++] != s[j--]) return false;
        return true; 
    }
public:
    vector<int> dp;
    int solve(string &s, int st){
        if(st >= s.size() - 1) return 0;
        if(dp[st] != -1) return dp[st];
        int ans = s.size();
        for(int k = st; k < s.size(); k++){
            if(isPalin(s, st, k)){
                ans = min(ans, (k != s.size() - 1) + solve(s, k + 1));
            }
        }
        return dp[st] = ans;
    }
    
    int minCut(string s) {
        dp.resize(s.size(), -1);
        return solve(s, 0);
    }
};