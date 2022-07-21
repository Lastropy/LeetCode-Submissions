class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char c: t)
            mp[c]++;
        int i, j;
        int len = INT_MAX;
        string ans = "";
        int n = s.size();
        int uniq= mp.size();
        for(i = 0, j = 0; j < n; j++){
            if(mp.find(s[j])!= mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    uniq--;
            }
            while(i < n && uniq == 0){
                int currLen = j - i + 1;
                if(currLen < len){
                    len = min(currLen, len);
                    ans = s.substr(i,j-i+1);
                }
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1)
                        uniq++;
                }
                i++;
            }
        }
        return ans;
    }
};