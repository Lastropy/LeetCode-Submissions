class Solution {
public:
    vector<int> dp;
    bool isValid(string &s, int st, int e){
        if(e == st){
            if(s[e] >= '1' && s[e] <= '9') return true;
            return false;
        } 
        if(s[st] == '0') return false;
        if(s[st] > '2') return false;
        if(s[st] == '2' && s[e] > '6') return false;
        return true;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        dp.resize(n+1, 0);
        dp[n] = 1;
        for(int idx = n - 1; idx >= 0; idx --){
            if(isValid(s, idx, idx)){
                dp[idx] += dp[idx + 1];
            } if(idx + 1 < s.size() && isValid(s, idx, idx + 1)){
                dp[idx] += dp[idx + 2];
            }
        }
        return dp[0];
    }
};