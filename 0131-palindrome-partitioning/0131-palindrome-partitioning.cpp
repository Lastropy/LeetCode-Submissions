class Solution {
public:
    bool isPalin(string &s, int st, int en){
        if(st >= en) return true;
        return (s[st] == s[en]) && isPalin(s, st + 1, en - 1);
    }
    void solve(vector<vector<string>> &ans, string &s, vector<string> &curr, int idx){
        if(idx == s.size()){
            ans.push_back(curr);
            return;
        }
        
        for(int i = idx; i < s.size(); i++){
            if(isPalin(s, idx, i)){
                curr.push_back(s.substr(idx, i - idx  + 1 ));
                solve(ans, s, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(ans, s, curr, 0);
        return ans;
    }
};