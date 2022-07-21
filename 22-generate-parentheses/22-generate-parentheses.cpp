class Solution {
public:
    void f(int o, int c, vector<string> &ans, string p=""){
        if( o < 0 || c < 0 ) return;
        if(o == 0 && c == 0){
            ans.push_back(p);
            return;
        }
        if(c > o )f(o , c-1 , ans, p + ")");
        f(o - 1, c , ans , p + "(");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(n, n, ans);
        return ans;
    }
};