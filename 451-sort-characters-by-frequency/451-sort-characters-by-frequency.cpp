class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c: s)
            mp[c]++;
        sort(begin(s), end(s), [&](char a, char b) {
            return mp[a] == mp[b]? a > b : mp[a] > mp[b];
        });
        return s;
    }
};