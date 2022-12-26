class Solution {
public:
    vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040};
    unordered_set<string> seen;
    
    int uniquePerm( vector<int> &cnt){
        int len = 0;
        for(int i: cnt) len += i;
        int ans = fact[len];
        for(int i: cnt) ans /= fact[i];
        return ans;
    }
    string getHash(vector<int> &cnt){
        string hash = "";
        for(int i: cnt)
            hash += string(1, i + '0') + "_";
        return hash;
    }
    int dfs(string &s, vector<int> cnt = vector<int>(26, 0), int pos = 0){
        if(pos >= s.size()){
            if(!(seen.insert(getHash(cnt)).second)) return 0;
            return uniquePerm(cnt);
        }
        
        cnt[s[pos] - 'A']++;
        int take = dfs(s, cnt, pos + 1);
        cnt[s[pos] - 'A']--;
        int ntake = dfs(s, cnt , pos + 1);
        return take + ntake;
    }
    
    
    int numTilePossibilities(string tiles) {
        sort(begin(tiles), end(tiles));
        return dfs(tiles) - 1;       
        
    }
};