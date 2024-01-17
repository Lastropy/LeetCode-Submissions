class Solution {
public:
    int try_character(string &s, int k ,char ch){
        int ans = 0, curr = 0, n = s.size();
        for(int i =0, j = 0; j < n; j++){
            if(s[j] != ch) curr++;
            while(i < j && curr > k){
                curr -= (s[i] != ch);
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        vector<int> f(26, 0);
        for(char c: s)
            f[c - 'A']++;
        int ans = 0;
        for(int i = 0; i < 26; i++)
            if(f[i]) 
                ans = max(ans, try_character(s, k, 'A' + i));
        return ans;
    }   
};