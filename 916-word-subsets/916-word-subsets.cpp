class Solution {
public:
    bool check(vector<int> f, string s){
        vector<int> f2(26, 0);
        for(int i = 0; i < s.size(); i++)
            f2[s[i]-'a']++;
        for(int i = 0; i < 26; i++){
            if(f2[i] < f[i])
                return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> gf(26, 0 );
        for(string w: words2){
            vector<int> curr(26, 0);
            for(char c: w)
                gf[c-'a'] = max(++curr[c - 'a'], gf[c-'a']);
        } 
        for(string w: words1){
            if(check(gf, w))
                ans.push_back(w);
        }
        return ans;
    }
};