class Solution {
public:
    vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040};
    unordered_set<string> seen;
    
    int uniquePerm(string &seq){
        vector<int> cnt(26, 0);
        for(char c: seq)
            cnt[c - 'A']++;
        int ans = fact[seq.size()];
        for(int i: cnt) ans /= fact[i];
        return ans;
    }
    int dfs(string &s, string seq = "", int pos = 0){
        if(pos >= s.size()){
            if(seen.find(seq) != seen.end()) return 0;
            seen.insert(seq);
            return uniquePerm(seq);
        }
        
        int take = dfs(s, seq + s[pos], pos + 1);
        int ntake = dfs(s, seq , pos + 1);
        return take + ntake;
    }
    
    
    int numTilePossibilities(string tiles) {
        sort(begin(tiles), end(tiles));
        return dfs(tiles) - 1;       
        
    }
};