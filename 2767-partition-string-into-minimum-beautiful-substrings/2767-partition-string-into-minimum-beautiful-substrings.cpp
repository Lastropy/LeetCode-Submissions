class Solution {
public:
    vector<int> dp;
    int solve(string &s, int len, unordered_set<string>& valid){
        if(len == 0) return 0;
        if(dp[len] != -1) return dp[len];
        int ans = 1e9;
        for(int idx = len - 1; idx >= 0; idx--){
            string pos = s.substr(idx, len - idx);
            if(valid.find(pos) != valid.end()){
                ans = min(ans, 1 + solve(s, idx, valid));
            }
        }
        return dp[len] = ans;
    }
    
    int minimumBeautifulSubstrings(string s) {
        // '1', '101', '11001', '1111101', '1001110001', '110000110101', '11110100001001'
        unordered_set<string> valid({"1", "101", "11001", "1111101", "1001110001", "110000110101", "11110100001001"});
        int n = s.size();
        dp.resize(n + 1, -1);
        int ans = solve(s, n, valid);
        if(ans >= 1e9) return -1;
        return ans;
    }
};