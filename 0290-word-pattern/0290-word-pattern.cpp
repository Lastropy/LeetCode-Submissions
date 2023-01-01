class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;

        stringstream str(s);
        int pos = 0;
        while(getline(str, s, ' ')){
            if((mp.count(pattern[pos]) && mp[pattern[pos]] != s ) || (mp2.count(s) && mp2[s] != pattern[pos]))
                return false;
            mp[pattern[pos]] = s;
            mp2[s] = pattern[pos++];
        }
        return pos == pattern.size();
    }
};