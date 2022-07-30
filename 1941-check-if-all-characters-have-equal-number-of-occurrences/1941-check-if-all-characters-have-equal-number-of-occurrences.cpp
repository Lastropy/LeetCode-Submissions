class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> f(26,0);
        int mx = INT_MIN;
        for(char c : s){
            f[c - 'a']++;
            mx = max(mx, f[c-'a']);
        }
        for(int i= 0; i < 26; i++)
            if(f[i] && f[i] != mx)
                return false;
        return true;
    }
};