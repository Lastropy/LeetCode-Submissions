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
        int prev1 = 1; // dp[idx + 1]
        int prev2; // dp[idx + 2]
        int curr = 0; // dp[idx]
        for(int idx = n - 1; idx >= 0; idx --){
            curr = 0;
            if(isValid(s, idx, idx)){
                curr += prev1;
            } if(idx + 1 < s.size() && isValid(s, idx, idx + 1)){
                curr += prev2;
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};