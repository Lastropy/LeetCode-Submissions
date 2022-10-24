class Solution {
public:
    bool isCompatible(vector<int> &f, string &s, string &res){
        // cout << "checking for " << res << " & " << s<< endl;
        for(char c: s){
            if(f[c - 'a'] == 1)
                return false;
        }
        return true;
    }
    void solve(vector<string> &a, int idx, int &ans, vector<int> curr, string res=""){
        int n = a.size();
        if(idx == n) return;
        
        
        for(char c: a[idx]){
            if(curr[c-'a']) return;
            curr[c - 'a']++;
        }
        
        res += a[idx];
        int tot = 0;
        for(int i: curr ) tot += i;
        // cout << res << " " << tot << endl;
        ans = max(tot, ans);
        
        for(int i = idx + 1; i < n; i++){
            if(isCompatible(curr, a[i], res)){
                solve(a, i, ans, curr, res);
            }
        }
        
        
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        
        int ans = 0;
        vector<int> curr(26, 0);
        for(int i = 0; i < n; i++)
            solve(arr, i, ans, curr);
        return ans;
        
    }
};