class Solution {
public:
    int diff(string &a, string &b){
        if(a== b) return 0;
        int ans = 0;
        for(int i =0; i < 8; i++)
            ans += (a[i] != b[i]);
        return ans;  
    }
    int solve(string start, string end, set<string>& b){
        if(start == end) return 0;
        int ans = 1e9;

        set<string> cpy(b.begin(), b.end());
        for(string s: cpy){
            if(diff(start, s) == 1){
                string temp = s;
                b.erase(temp);
                int curr = 1 + solve(temp, end, b);
                ans = min(ans, curr);
                b.insert(temp);
            }
        }
        return ans;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> b;
        for(string s: bank){
            b.insert(s);
        }
        
        int ans = solve(start, end, b);
        return ans >= 1e9 ? -1 : ans;
    }
};