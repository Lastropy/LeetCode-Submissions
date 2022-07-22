class Solution {
public:
    vector<string> f(string &s, int st, set<string> &t,  unordered_map<int, vector<string>> &dp){
        if(st == s.size()) return vector<string>();
        if(dp.count(st)) return dp[st];
        string res = "";
        vector<string> ans;
        if(t.find(s.substr(st)) != t.end())
            ans.push_back(s.substr(st));
        for(int i = st; i < s.size() - 1; i++){
            res += s[i];
            if(t.find(res) != t.end()){
                // cout << res << endl;
                auto temp2 = f(s, i+1,t, dp);
                if(temp2.size() > 0 )
                {
                    for(string k: temp2){
                        ans.push_back(res+" "+ k);
                    }
                }
            }
        }
        return dp[st] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, vector<string>> mp;
        set<string> t;
        for(string w: wordDict)
            t.insert(w);
        auto ans = f(s, 0, t, mp);
        return ans;
    }
};