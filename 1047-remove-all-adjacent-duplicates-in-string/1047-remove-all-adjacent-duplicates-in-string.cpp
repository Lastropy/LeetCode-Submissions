class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(char c: s){
            if(!ans.empty() && ans.back() == c){
                ans.erase(ans.size() - 1, 1);
                continue;
            }
            ans += c;
        }
        return ans;
    }
};