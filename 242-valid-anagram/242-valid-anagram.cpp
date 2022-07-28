class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;
        for(char c: s)
            mp[c]++;
        for(char c: t)
            mp[c]--;
        for(auto [k,v]:mp)
            if(v != 0)
                return false;
        return true;
    }
};