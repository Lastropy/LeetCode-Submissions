class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k > n) return false;
        if(k == n) return true;
        unordered_map<char, int> mp;
        for(char c: s) mp[c]++;
        if(mp.size() <= k) return true;
        int odders = 0;
        for(auto [k, v]: mp) odders+= (v % 2);
        return k >= odders;       
    }
};