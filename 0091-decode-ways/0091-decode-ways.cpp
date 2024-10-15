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
    
    int solve(int idx, string &s){
        if(idx >= s.size()) return 1;
        if(dp[idx] != -1) return dp[idx];
        // cout << "trying "<< idx << endl; 
        int ans = 0;
        if(isValid(s, idx, idx)){
            ans += solve(idx + 1, s);
        }
        if(idx != s.size() - 1 && isValid(s, idx, idx+1)){
            ans += solve(idx + 2, s);
        }
        return dp[idx] = ans;
    }
    
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        int n = s.size();
        dp.resize(n+1, -1);
        solve(0, s);
        return dp[0];
    }
};