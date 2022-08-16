class Solution {
public:
    bool check(string &p, string &n){
        if(n.size() - p.size() != 1) return false;
        int p1 = 0, p2 = 0;
        while(p1 < p.size() && p2 < n.size()){
            if(p[p1] == n[p2]){
                p1++;
                p2++;
            }
            else p2++;
        }
        return p2 - p1 <= 1;
    }
    int longestStrChain(vector<string>& w) {
        sort(begin(w), end(w), [&](string a, string b){
          return a.size() == b.size() ? a < b: a.size() < b.size();  
        });

        vector<int> dp(w.size(), 1);
        int ans = INT_MIN;

        for(int idx = 0; idx < w.size(); idx++){
            for(int prev = 0; prev < idx; prev++)
                if(check(w[prev], w[idx]))
                    dp[idx]  = max(dp[idx], dp[prev]+1);
            ans = max(ans, dp[idx]);
        }
        return ans;
    }
};