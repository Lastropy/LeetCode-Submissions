class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        int n = s.size(), m = p.size();
        double succ = success;
        sort(p.begin(), p.end());
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++){
            long long tar = ceil(succ / s[i]);
            ans[i] = m - (lower_bound(p.begin(), p.end(), tar) - p.begin());
            
            
        }
        return ans;
    }
};